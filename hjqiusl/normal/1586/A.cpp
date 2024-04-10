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
int T,n,a[N];
int check(int x)
{
	for (int i=2;i*i<=x;i++)
		if (x%i==0) return 1;
	return 0;
}
signed main()
{
	T=read();
	while (T--)
	{
		int sm=0;
		vector<int>g,g1;
		n=read();
		for (int i=1;i<=n;i++)
			a[i]=read(),sm+=a[i];
		for (int i=1;i<=n;i++)
			if (a[i]%2==1) g.push_back(i);
			else g1.push_back(i);
//		cout<<check(11)<<endl;
		if (check(sm))
		{
			writeln(n);
			for (int i=1;i<=n;i++) writesp(i);
			puts("");
			continue;
		}
		writeln(g.size()-g.size()%2+g1.size());
		for (int i=0;i<g.size()-g.size()%2;i++) writesp(g[i]);
		for (auto u:g1) writesp(u);
		puts("");
	}
}
/*

*/