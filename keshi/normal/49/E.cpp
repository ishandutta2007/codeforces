//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 60;
const ll maxm = 1000;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, k, g[maxm], dp[maxn][maxn], pd[maxn][maxn], ans[maxn][maxn];
string s, t;

int main(){
    fast_io;
    
    cin >> s >> t;
    n = Sz(s);
    m = Sz(t);
    cin >> k;
    for(ll i = 0; i < k; i++){
    	char a, b, c, d;
    	cin >> a >> d >> d >> b >> c;
    	g[(b - 'a') * 26 + (c - 'a')] |= (1 << (a - 'a'));
	}
	for(ll i = n; i--;){
		dp[i][i + 1] = (1 << (s[i] - 'a'));
		for(ll j = i + 2; j <= n; j++){
			for(ll k = i + 1; k < j; k++){
				ll x = dp[i][k], y = dp[k][j];
				for(ll a = 0; a < 26; a++){
					if(((x >> a) & 1) == 0) continue;
					for(ll b = 0; b < 26; b++){
						if(((y >> b) & 1) == 0) continue;
						dp[i][j] |= g[a * 26 + b];
					}
				}
			}
		}
	}
	for(ll i = m; i--;){
		pd[i][i + 1] = (1 << (t[i] - 'a'));
		for(ll j = i + 2; j <= m; j++){
			for(ll k = i + 1; k < j; k++){
				ll x = pd[i][k], y = pd[k][j];
				for(ll a = 0; a < 26; a++){
					if(((x >> a) & 1) == 0) continue;
					for(ll b = 0; b < 26; b++){
						if(((y >> b) & 1) == 0) continue;
						pd[i][j] |= g[a * 26 + b];
					}
				}
			}
		}
	}
	for(ll i = 0; i < maxn; i++){
		fill(ans[i], ans[i] + maxn, inf);
	}
	ans[Sz(s)][Sz(t)] = 0;
	for(ll i = Sz(s); i--;){
		for(ll j = Sz(t); j--;){
			ans[i][j] = inf;
			for(ll i1 = i + 1; i1 <= Sz(s); i1++){
				for(ll j1 = j + 1; j1 <= Sz(t); j1++){
					if(dp[i][i1] & pd[j][j1]) ans[i][j] = min(ans[i][j], ans[i1][j1] + 1);
				}
			}
		}
	}
	if(ans[0][0] >= inf) ans[0][0] = -1;
	cout << ans[0][0];
 
    return 0;
}