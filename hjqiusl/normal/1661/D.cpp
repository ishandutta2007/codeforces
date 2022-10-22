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
int n,m,a[N],b[N],ans;
void BellaKira()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=a[i];
	if (n==m)
	{
		int now=0;
		for (int i=1;i<=m;i++)
			if (a[i]>=0)
				now=max(now,(a[i]/i)+(a[i]%i>0));
		writeln(now);
		return;
	}
	queue<int>q;
	int sm=(int)((a[n])/m+((a[n])%m>0))*m;
	int sm1=((a[n])/m+((a[n])%m>0));
	ans+=((a[n])/m+((a[n])%m>0));
	
	q.push(ans);
	for (int i=n-1;i>m;i--)
	{
		if (q.size()==m)
		{
			sm-=q.front();
			sm1-=q.front();
			q.pop();
		}
		// cout<<i<<" "<<q.size()<<endl;
		sm-=sm1;
		int x=min(m,i);
		int now=(a[i]-sm)/x+((a[i]-sm)%m>0);
		now=max(now,0ll);
		b[i]-=sm;
		b[i]-=now*x;
		q.push(now);
		sm+=now*x;
		sm1+=now;
		ans+=now;
	}
	
	for (int i=m;i>=1;i--)
	{
		if (q.size()==m)
		{
			sm-=q.front();
			sm1-=q.front();
			q.pop();
		}
		sm-=sm1;
		a[i]-=sm;
		q.push(0);
	}
	
	int now=0;
	for (int i=1;i<=m;i++)
		if (a[i]>=0)
			now=max(now,(a[i]/i)+(a[i]%i>0));
		
	writeln(ans+now);
			
			
		
		
		
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/