//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short us;
typedef unsigned int ui;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
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
const int N=5e4+5;
char s[N];
int mn[N],v[N];
priority_queue<pii> q;

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	int sum=0,m=0;
	rep(i,1,n)
	{
		if(s[i]=='?')
		{
			++m;
			++sum;
		}
		else
		if(s[i]=='(')++sum;
		else --sum;
		if(sum<0)
		{
			puts("-1");
			return 0;
		}
	}
	int need=sum/2;
	ll ans=0;
	rep(i,1,m)
	{
		int a=read(),b=read();
		ans+=a;v[i]=b-a;
	}	

	int now=0;
	per(i,n,1)
	{
		mn[i]=now;
		if(s[i]=='?'||s[i]=='(')chmin(++now,0);
		else --now;
	}

	sum=0;m=0;
	rep(i,1,n)
	if(s[i]=='?')
	{
		s[i]='(';
		++m;
		if(sum-1+mn[i]>=0) 
		{
			--sum;
			q.push(mp(v[m],i));
		}
		else
		{
			++sum;
			if(!q.empty()&&v[m]<q.top().first)
			{
				q.pop();
				q.push(mp(v[m],i));
			}
		}
	}
	else
	if(s[i]=='(')++sum;
	else --sum;

	while(!q.empty())
	{
		pii pr=q.top();q.pop();
		ans+=pr.first;s[pr.second]=')';
		--need;
	}
	if(need){puts("-1");return 0;}
	printf("%lld\n",ans);
	printf("%s\n",s+1);
}