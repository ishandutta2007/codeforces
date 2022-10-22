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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,a[N],b[N],l[N],r[N],L,R,s;
void What_will_Diana_eat_today()
{
	n=read();m=read();
	s=0,L=0,R=0;
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read();
		l[i]=max(0ll,m-b[i]);
		r[i]=min(a[i],m);
		L+=l[i],R+=r[i];
		s+=a[i]-b[i]+m;
	}
//	cout<<L<<" "<<R<<" "<<s<<endl;
	if (s<=2*L)
	{
		writeln(2*L-s);
		for (int i=1;i<=n;i++)
		{
			cout<<l[i]<<" "<<m-l[i]<<endl;
		}
	} else
	if (2*R<=s)
	{
		writeln(s-2*R);
		for (int i=1;i<=n;i++)
		{
			cout<<r[i]<<" "<<m-r[i]<<endl;
		}
	} else
	{
		writeln(s%2);
		s-=2*L;
		for (int i=1;i<=n;i++)
		{
			if ((r[i]-l[i])*2<=s)
			{
				s-=(r[i]-l[i])*2;
				l[i]=r[i];
			} else
			{
				l[i]+=s/2;
				break;
			}
		}
		for (int i=1;i<=n;i++)
		{
			cout<<l[i]<<" "<<m-l[i]<<endl;
		}
	}
				
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