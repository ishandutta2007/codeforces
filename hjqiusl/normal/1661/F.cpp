//~~
#pragma GCC optimize("Ofast",2,3)
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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
// #define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,ans,a[N];
int cnt;
int vl[N];
int p[N],c[N];
int tot;
priority_queue<pa>q;
inline int cc(int x)
{
	return x*x;
}
inline int calc(int x,int y)
{
	int res=y;
	return cc(res/(x+1))*(x+1-res%(x+1))+cc(res/(x+1)+1)*(res%(x+1));
}
map<int,int>Mp;
void BellaKira()
{
	n=read();
	int now=0;
	cnt=0;
	// cout<<"?"<<a[1]<<endl;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		Mp[a[i]-a[i-1]]++;
	}
	for (auto u:Mp)
	{
		p[++cnt]=0;
		c[cnt]=u.fi;
		vl[cnt]=u.se;
		ans+=calc(0,c[cnt])*vl[cnt];
		if (c[cnt]!=1)
		{
			q.push(mp(-calc(p[cnt]+1,c[cnt])+calc(p[cnt],c[cnt]),cnt));
		}
	}
	m=read();
	while (ans>m)
	{
		int x=q.top().se;
		int w=q.top().fi;
		q.pop();
		int nowp=-inf;
		if (q.size()) nowp=q.top().fi;
		int l=p[x]+1,r=c[x],nxt=p[x]+1;
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if (-calc(mid,c[x])+calc(mid-1,c[x])<nowp||ans+(-calc(p[x],c[x])+calc(mid,c[x]))*vl[x]<=m)
			{
				r=mid-1;
			} 
			else 
			{
				nxt=mid;
				l=mid+1;
			}
		}
		nxt--;
		if (nxt==p[x]) nxt++;
		if (ans+(-calc(p[x],c[x])+calc(nxt,c[x]))*vl[x]<=m)
		{
			l=1,r=vl[x];
			int now=-1;
			while (l<=r)
			{
				int mid=l+(r-l)/2;
				if (ans+(-calc(p[x],c[x])+calc(nxt,c[x]))*mid+(-calc(p[x],c[x])+calc(nxt-1,c[x]))*(vl[x]-mid)<=m)
				{
					now=mid;
					r=mid-1;
				} else l=mid+1;
			}
			tot+=now*(nxt-p[x])+(vl[x]-now)*(nxt-p[x]-1);
			ans+=(-calc(p[x],c[x])+calc(nxt,c[x]))*now;
			ans+=(-calc(p[x],c[x])+calc(nxt-1,c[x]))*(vl[x]-now);
			break;
		}
		tot+=(vl[x])*(nxt-p[x]);
		ans+=(-calc(p[x],c[x])+calc(nxt,c[x]))*vl[x];
		p[x]=nxt;
		if (p[x]!=c[x])
			q.push(mp(-calc(p[x]+1,c[x])+calc(p[x],c[x]),x));
	}
	writeln(tot);
	while (!q.empty()) q.pop();
	ans=0;
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