//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 110;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, dp[maxn][maxn][maxn], sz[maxn], d2[maxn], pd[maxn][maxn], C[maxn][maxn];
vector<ll> g[maxn];
bool vis[maxn];

ll pw(ll a, ll b){
	if(b < 0) b += mod - 1;
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

void dfs(ll v){
	vis[v] = 1;
	sz[v] = 1;
	dp[v][0][1] = 1;
	for(ll u : g[v]){
		if(vis[u]) continue;
		dfs(u);
		for(ll i2 = 0; i2 < sz[v]; i2++){
			for(ll j2 = 1; j2 <= sz[v]; j2++){
				for(ll i = 0; i < sz[u]; i++){
					for(ll j = 1; j <= sz[u]; j++){
						pd[i2 + i + 1][j2 + j] += dp[v][i2][j2] * dp[u][i][j];
						pd[i2 + i + 1][j2 + j] %= mod;
						pd[i2 + i][j2] += dp[v][i2][j2] * dp[u][i][j] % mod * j;
						pd[i2 + i][j2] %= mod;
					}
				}
			}
		}
		sz[v] += sz[u];
		for(ll i = 0; i < sz[v]; i++){
			for(ll j = 1; j <= sz[v]; j++){
				dp[v][i][j] = pd[i][j];
				pd[i][j] = 0;
			}
		}
	}
	return;
}

int main(){
    fast_io;

	C[0][0] = 1;
	for(ll i = 1; i < maxn; i++){
		C[i][0] = 1;
		for(ll j = 1; j < maxn; j++){
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			if(C[i][j] >= mod) C[i][j] -= mod;
		}
	}

	cin >> n;
	for(ll i = 1; i < n; i++){
		ll v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1);
	for(ll i = 0; i < n; i++){
		for(ll j = 1; j <= n; j++){
			d2[i] = (d2[i] + dp[1][i][j] * pw(n, n - i - 2) % mod * j) % mod;
		}
	}
	for(ll i = n; i--;){
		for(ll j = i + 1; j < n; j++){
			d2[i] = (d2[i] - d2[j] * C[j][i]) % mod;
		}
	}
	for(ll i = 0; i < n; i++){
		cout << (d2[i] + mod) % mod << " ";
	}

    return 0;
}