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
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n;
int a[N],b[N],c[N],l[N],r[N];
vector<int>g[N];
int ans;
bool cmp(int x,int y)
{
	return (r[x]^r[y])?r[x]<r[y]:l[x]<l[y];
}
void What_will_Diana_eat_today()
{
	n=read();
	vector<int>g1;
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read(),c[i]=read();
		l[i]=a[i]-max(0ll,c[i]-b[i]);
		r[i]=a[i]-min(c[i],a[i]);
		swap(l[i],r[i]);
//		cout<<"!"<<i<<" "<<l[i]<<" "<<r[i]<<endl;
		g[a[i]+b[i]-c[i]].push_back(i);
		g1.push_back(a[i]+b[i]-c[i]);
	}
	sort(g1.begin(),g1.end());
	g1.erase(unique(g1.begin(),g1.end()),g1.end());
	ans=0;
	for (int i:g1)
	{
		sort(g[i].begin(),g[i].end(),cmp);
		int mx=-1;
		for (auto u:g[i])
		{
			if (mx>=l[u]) 
			{
				l[u]=mx;
				continue;
			}
			ans++;
			mx=r[u];
			l[u]=r[u];
		}
		vector<int>().swap(g[i]);
	}
	writeln(ans);
	for (int i=1;i<=n;i++) 
	{
		writesp(a[i]-l[i]),writeln((c[i]-(a[i]-l[i])));
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