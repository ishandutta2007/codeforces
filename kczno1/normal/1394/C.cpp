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

const int N=3e5+5,INF=2e6;
int n,x[N],y[N];
char s[INF];

pii seg[4];
void UP(int i,int l,int r)
{
	chmax(seg[i].first,l);
	chmin(seg[i].second,r);
}
bool check(int mid)
{
	rep(i,0,2)seg[i]=pii(-INF,INF);
	rep(i,1,n)
	{
		UP(0,max(0,x[i]-mid),x[i]+mid);
		UP(1,max(0,y[i]-mid),y[i]+mid);
		int v=x[i]-y[i];
		UP(2,v-mid,v+mid);
	}	
	UP(2,seg[0].first-seg[1].second,seg[0].second-seg[1].first);
	//if(mid==1)
	//rep(i,0,2)
		//cerr<<seg[i].first<<" "<<seg[i].second<<endl;
	rep(i,0,2)
	if(seg[i].first>seg[i].second)return 0;
	return 1;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n;
	rep(i,1,n)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		rep(j,1,len)
		if(s[j]=='B')++x[i];
		else ++y[i];
	}
	int l=-1,r=INF;
	while(l+1!=r)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout<<r<<endl;
	check(r);
	rep(x,seg[0].first,seg[0].second)
	{
		seg[3]=seg[1];
		UP(3,max(x-seg[2].second,x?0:1),x-seg[2].first);
		if(seg[3].first<=seg[3].second)
		{
			rep(i,1,x)s[i]='B';
			rep(i,x+1,x+seg[3].first)s[i]='N';
			s[x+seg[3].first+1]=0;
			printf("%s\n",s+1);
			exit(0);
		}	
	}
}