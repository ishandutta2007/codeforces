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
#define N 500005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],dp[N];
vector<pa>G;
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		vector<pa>now;
		for (auto u:G)
		{
			int x=u.fi,y=u.se;
			x=__gcd(x,a[i]);
			if (now.size()&&now.back().fi==x) continue;
			now.push_back(mp(x,y));
		}
		if (!(now.size()&&a[i]==now.back().fi)) now.push_back(mp(a[i],i));
		int x=i+1;
		int lst=-1;
		for (int j=now.size()-1;j>=0;j--)
		{
			int L=i-(x-1)+1,R=i-now[j].se+1;
			// cout<<L<<" "<<R<<" "<<now[j].fi<<endl;
			x=now[j].se;
			if (L<=now[j].fi&&now[j].fi<=R) 
			{
				lst=now[j].fi;
				break;
			}
		}
		// cout<<lst<<endl;
		if (lst!=-1)
			dp[i]=max(dp[i-1],dp[i-lst]+1);
		else dp[i]=dp[i-1];
		writesp(dp[i]);
		swap(G,now);
	}
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