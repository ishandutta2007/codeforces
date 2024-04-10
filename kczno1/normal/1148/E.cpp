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

const int N=3e5+5;
int s[N],t[N],id[N];
pii s0[N];
vector<tuple<int,int,int>>ans;

void P(int i,int j,int d)
{
	s[i]+=d;s[j]-=d;
	ans.push_back(tuple<int,int,int>(id[i],id[j],d));
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	deque<int>q;
	int n;
	cin>>n;
	s64 sum=0;
	rep(i,1,n)
	{
		int x;
		sum+=(x=read());
		s0[i]={x,i};
	}
	rep(i,1,n)sum-=(t[i]=read());
	if(sum){puts("NO");exit(0);}
	sort(s0+1,s0+n+1);sort(t+1,t+n+1);
	rep(i,1,n)tie(s[i],id[i])=s0[i];
	per(i,n,1)
	if(s[i]>t[i])q.push_front(i);
	else
	while(s[i]<t[i])
	{
		if(q.empty()){puts("NO");exit(0);}
		int j=q.front();
		if(s[j]-t[j]>=t[i]-s[i])
		{
			P(i,j,t[i]-s[i]);
			break;
		}
		P(i,j,s[j]-t[j]);
		q.pop_front();
	}
	puts("YES");
	printf("%d\n",int(ans.size()));
	for(auto p:ans)
	{
		int i,j,d;
		tie(i,j,d)=p;
		printf("%d %d %d\n",i,j,d);
	}
}