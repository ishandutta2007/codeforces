#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC


#define forn(i, n) for (int i = 0; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())

#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))

void gett()
{
	cerr<< (clock())/(double)cps<<endl;
}

const ll mod = 1e9+7;

ll powr(ll a, ll b)
{
	ll x = 1%mod;
	a %= mod;
	while(b)
	{
		if(b&1)
			x = (x*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return x;
}
ll inv(ll a)
{
	return powr(a,mod-2);
}

const int maxn = 1e6+10;
const int N = 505;
bitset<N> dp[N][N];
int C[N];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
		cin>>C[i];
	dp[0][0].set(0);
	bitset<N> use;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 0;j<=k;j++)
			dp[i][j] = dp[i-1][j];
		for(int j = 0;j+C[i]<=k;j++)
		{
			use = dp[i-1][j];
			for(int l = 0;l<=j;l++)
			{
				if(dp[i-1][j][l])
					use[l+C[i]] = 1;
			}
			dp[i][j+C[i]] = dp[i-1][j+C[i]] | use;
		}
	}
	int cnt = dp[n][k].count();
	cout<<cnt<<"\n";
	for(int i = 0;i<=k;i++)
		if(dp[n][k][i])
			cout<<i<<" ";

}