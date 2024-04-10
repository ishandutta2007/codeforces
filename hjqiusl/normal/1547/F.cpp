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
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int st[N][25];
int a[N];
int ans;
int n;
int query(int x,int y)
{
	int t=log2(y-x+1);
	return __gcd(st[x][t],st[y-(1<<t)+1][t]);
}
bool check(int len)
{
	int x=query(1,len);
	for (int i=1;i<=n;i++)
		if (query(i,i+len-1)!=x) return 0;
	return 1;
}
void What_will_Diana_eat_today()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=a[i+n]=read();
		st[i][0]=st[i+n][0]=a[i];
	}
	for (int i=1;i<=20;i++)
		for (int j=1;j+(1<<i)-1<=2*n;j++)
			st[j][i]=__gcd(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	int l=1,r=n;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (check(mid))
		{
			ans=mid;
			r=mid-1;
		} else l=mid+1;
	}
	writeln(ans-1);
	
}
signed main()
{
	int T=read();
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*

*/