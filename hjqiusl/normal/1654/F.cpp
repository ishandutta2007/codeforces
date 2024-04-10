//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define paa pair<int,string>  
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n;
string st;
poly work(poly G)
{
	if (G.size()==1) return G;
	vector<pa>Gx,Gy;
	for (int i=0;i<G.size();i+=2)
		Gx.push_back(mp(G[i],G[i+1])),
		Gy.push_back(mp(G[i+1],G[i]));
	sort(Gx.begin(),Gx.end());
	sort(Gy.begin(),Gy.end());
	poly nxtx,nxty;
	for (int i=0;i<G.size();i+=2)
	{
		nxtx.push_back(lower_bound(Gx.begin(),Gx.end(),mp(G[i],G[i+1]))-Gx.begin());
		nxty.push_back(lower_bound(Gy.begin(),Gy.end(),mp(G[i+1],G[i]))-Gy.begin());
	}
	poly nowx=work(nxtx);
	poly nowy=work(nxty);
	poly cmpx,cmpy;
	for (int i=0;i<G.size();i+=2)
	{
		cmpx.push_back(Gx[nowx[i/2]].fi);
		cmpx.push_back(Gx[nowx[i/2]].se);
		cmpy.push_back(Gy[nowy[i/2]].fi);
		cmpy.push_back(Gy[nowy[i/2]].se);
	}
	int bl=0;
	for (int i=0;i<G.size();i++)
		if (cmpx[i]<cmpy[i])
		{
			bl=0;
			break;
		} else
		if (cmpy[i]<cmpx[i])
		{
			bl=1;
			break;
		}
	if (bl) return cmpy;
	return cmpx;
}
void BellaKira()
{

	cin>>n>>st;
	poly G;
	for (auto u:st) G.push_back(u);
	G=work(G);
	for (auto u:G) cout<<(char)(u);
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