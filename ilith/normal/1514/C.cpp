//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e5+5;
int n;
inline void init()
{

}
inline void input()
{
	n=gi();
}
inline bool is_prime(int x)
{
	for(int i=2;i*i<=x;++i)
	{
		if(x%i==0)return 0;
	}
	return 1;
}
inline void solve()
{
	if(is_prime(n))
	{
		if(n==2)printf("1\n1\n");
		else
		{
			printf("%d\n",n-2);
			FOR(i,1,n-2)printf("%d ",i);
		}
	}
	else
	{
		vector<int>ans;
		int sum=1;
		FOR(i,1,n-2)
		{
			if(__gcd(n,i)==1)ans.pb(i),sum=1ll*sum*i%n;
		}
		if(sum!=1)ans.pb(n-1);
		printf("%d\n",sz(ans));
		for(int x:ans)printf("%d ",x);
	}
}
int main()
{
	int T=1;
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}