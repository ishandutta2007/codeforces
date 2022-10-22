//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],b[N];
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int ans=inf;
	int x=0,y=0,z=0,res=0,g=0,mx=0;
	for (int i=1;i<=n;i++)
	{
		b[i]=a[i];
		if (a[i]%2==0) x++,b[i]=a[i]+1;
	}
	for (int i=1;i<=n;i++) mx=max(mx,b[i]);
	for (int i=1;i<=n;i++)
	{
		if (a[i]%2==0)
			y=(y+(mx-b[i])/2);
		else z=(z+(mx-b[i])/2);
	}
	
	
	
	g=min(x,z);
	res+=g*2;
	x-=g,z-=g;
	if (x==0)
	{
		z*=2,y*=2;
		if ((z+y)%3==0)
		{
			res+=(z+y)/3*2;
		} else 
		{
			if ((z+y)%3==1)
			{
				res+=(z+y-4)/3*2+3;
			} else
			if ((z+y)%3==2)
			{
				res+=(z+y)/3*2+2;
			}
		}
	} else
	{
		if (x>y)
		{
			res+=x*2-1;
		} else
		{
			res+=x*2;
			y-=x;
			
			y*=2;
			if ((z+y)%3==0)
			{
				res+=(z+y)/3*2;
			} else 
			{
				if ((z+y)%3==1)
				{
					res+=(z+y-4)/3*2+3;
				} else
				if ((z+y)%3==2)
				{
					res+=(z+y)/3*2+2;
				}
			}
		}
	}
	
	ans=min(ans,res);
	
	x=0,y=0,z=0,res=0,g=0,mx=0;
	for (int i=1;i<=n;i++)
	{
		b[i]=a[i];
		if (a[i]%2==1) x++,b[i]=a[i]+1;
	}
	for (int i=1;i<=n;i++) mx=max(mx,b[i]);
	for (int i=1;i<=n;i++)
	{
		if (a[i]%2==1)
			y=(y+(mx-b[i])/2);
		else z=(z+(mx-b[i])/2);
	}
	
	
	g=min(x,z);
	res+=g*2;
	x-=g,z-=g;
	if (x==0)
	{
		z*=2,y*=2;
		if ((z+y)%3==0)
		{
			res+=(z+y)/3*2;
		} else 
		{
			if ((z+y)%3==1)
			{
				res+=(z+y-4)/3*2+3;
			} else
			if ((z+y)%3==2)
			{
				res+=(z+y)/3*2+2;
			}
		}
	} else
	{
		if (x>y)
		{
			res+=x*2-1;
		} else
		{
			res+=x*2;
			y-=x;
			
			y*=2;
			if ((z+y)%3==0)
			{
				res+=(z+y)/3*2;
			} else 
			{
				if ((z+y)%3==1)
				{
					res+=(z+y-4)/3*2+3;
				} else
				if ((z+y)%3==2)
				{
					res+=(z+y)/3*2+2;
				}
			}
		}
	}
	
	ans=min(ans,res);
	
	writeln(ans);
	
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/