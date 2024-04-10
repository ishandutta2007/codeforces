#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=100+5;
int n,m,p[N];
#ifdef kcz
int p1[N];
#endif
int M(int x,int d)
{
	if(x==0)
	{
		rep(i,1,n-1)
		if(p[i])p[i]-=d;
	}

	printf("? %d %d\n",x,d);
	fflush(stdout);
	int ans;
#ifdef kcz
	p1[x]+=d;	
	static bool b[N*30];
	rep(i,0,n*m-1)b[i]=1;
	rep(i,0,n-1)
		rep(j,0,m-1)b[ ((p1[i]+j)%(n*m)+(n*m))%(n*m) ]=0;
	ans=0;
	rep(i,0,n*m-1)ans+=b[i];
	printf("%d\n",ans);
	return ans;
#endif
	scanf("%d",&ans);
	return ans;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n-1)p1[i]=read();
#else 
	srand(time(0));
	cin>>n>>m;
#endif


	bool last_is_blank=0;
	int a=M(0,-1);
	rep(tmp,1,n-1)
	while(1)
	{
		int na=M(0,-1);	
		if(na==a+1)
		{
			a=na;
			last_is_blank=1;
		}
		else 
		{
			if(!last_is_blank)
			{
				a=na;
				continue;
			}
			M(0,1);

			vector<int>q;
			rep(i,1,n-1)
			if(!p[i])q.push_back(i);
			random_shuffle(q.begin(),q.end());

			for(auto x:q)
			{
				int b=M(x,1);
				if(b!=a-1)
				{
					M(x,-1);
					continue;
				}
				int b0=M(0,1);
				int a0=M(x,-1);
				if(b0!=a0-1)
				{
					last_is_blank=0;
					p[x]=m;
					rep(i,1,p[x]+1)
					{
						a=M(x,1);
					}
			#ifdef kcz
				printf("p[x]=%d p1[x]=%d\n",p[x],((p1[x]-p1[0])%(n*m)+n*m)%(n*m));
			#endif
					break;
				}
				M(0,-1);
			}	
			break;
		}
	}
	printf("!");
	rep(i,1,n-1)printf(" %d",(p[i]%(n*m)+n*m)%(n*m));
	puts("");
#ifdef kcz
	rep(i,1,n-1)printf(" %d",((p1[i]-p1[0])%(n*m)+n*m)%(n*m));
	puts("");
#endif
}