//The Hunting Party - Keys To The Kingdom
//~
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 2005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int a[N],b[N],ans,n;
bool check()
{
	for (int i=1;i<=2*n;i++)
		if (b[i]!=a[i])return 0;
	return 1;
}
void work()
{
	for (int i=1;i<=n;i++) swap(b[i],b[i+n]);
}
void work1()
{
	for (int i=1;i<=2*n;i+=2)
		swap(b[i],b[i+1]);
}
void What_will_Diana_eat_today()
{
	n=read();
	for (int i=1;i<=2*n;i++) a[i]=read();
	if (n%2==0)
	{
		ans=1;
		if (a[2]==1)
		{
			for (int i=1;i<=2*n;i++)
			{
				if (i%2==1)
				{
					ans&=(a[i]==i+1);
				} else ans&=(a[i]==(i-1));
			}
			if (ans) puts("1");
			else puts("-1");
		} else
		if (a[1]==1)
		{
			for (int i=1;i<=2*n;i++)
				ans&=(a[i]==i);
			if (ans) puts("0");
			else puts("-1");
		} else
		if (a[n+1]==1)
		{
			for (int i=1;i<=n;i++)
				swap(a[i],a[i+n]);
			for (int i=1;i<=2*n;i++)
				ans&=(a[i]==i);
			if (ans) puts("1");
			else puts("-1");
		} else
		if (a[n+2]==1)
		{
			for (int i=1;i<=n;i++)
				swap(a[i],a[i+n]);
			for (int i=1;i<=2*n;i++)
			{
				if (i%2==1)
				{
					ans&=(a[i]==i+1);
				} else ans&=(a[i]==(i-1));
			}
			if (ans) puts("2");
			else puts("-1");
		} else puts("-1");
	} else
	{
		for (int i=1;i<=2*n;i++) b[i]=i;
		int tim=0;
		while (!check()&&tim<=2*n)
		{
			if (tim%2==0) work();
			else work1();
			tim++;
		}
		if (!check())
			tim=inf;
		ans=tim;
		for (int i=1;i<=2*n;i++) b[i]=i;
		tim=0;
		while (!check()&&tim<=2*n)
		{
			if (tim%2==1) work();
			else work1();
			tim++;
		}
		if (!check())
			tim=inf;
		ans=min(ans,tim);
		if (ans==inf) puts("-1");
		else writeln(ans);
	}		
}
signed main()
{
	int T=1;
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*

*/