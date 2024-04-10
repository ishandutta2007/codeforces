//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef double ld;
typedef pair<ll, ll> pll;

const ll maxn = 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ll lg = 10;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, a[maxn], b[maxn];
ld dp[lg][maxn][maxn], ans[maxn][maxn];
vector<ll> vec;

void add(ll x, ll h, ll y){
	ld l = 0;
	if(x > a[y]) l = 1.0 * (vec[x] - vec[a[y]]) / (vec[b[y]] - vec[a[y]]);
	if(l > 1) l = 1;
	ld r = 0;
	if(x + 1 < b[y]) r = 1.0 * (vec[b[y]] - vec[x + 1]) / (vec[b[y]] - vec[a[y]]);
	if(r > 1) r = 1;
	ld m = 1 - l - r;
	for(ll i = n; i--;){
		for(ll j = n; j--;){
			dp[h][i][j] = dp[h][i][j] * r + dp[h][i - 1][j] * l + dp[h][i][j - 1] * m;
		}
	}
}

void solve(ll x, ll s, ll e, ll h){
	if(e - s == 1){
		if(!(a[s] <= x && x < b[s])) return;
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				ans[s][i + j + 1] -= dp[h][i][j] / (j + 1) * (vec[x + 1] - vec[x]) / (vec[b[s]] - vec[a[s]]);
				ans[s][i] += dp[h][i][j] / (j + 1) * (vec[x + 1] - vec[x]) / (vec[b[s]] - vec[a[s]]);
			}
		}
		return;
	}
	ll mid = (s + e) >> 1;
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			dp[h + 1][i][j] = dp[h][i][j];
		}
	}
	for(ll i = mid; i < e; i++){
		add(x, h + 1, i);
	}
	solve(x, s, mid, h + 1);
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			dp[h + 1][i][j] = dp[h][i][j];
		}
	}
	for(ll i = s; i < mid; i++){
		add(x, h + 1, i);
	}
	solve(x, mid, e, h + 1);
	return;
}

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 0; i < n; i++){
    	cin >> a[i] >> b[i];
    	vec.pb(a[i]);
    	vec.pb(b[i]);
	}
	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	for(ll i = 0; i < n; i++){
		a[i] = lower_bound(all(vec), a[i]) - vec.begin();
		b[i] = lower_bound(all(vec), b[i]) - vec.begin();
	}
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			dp[0][i][j] = 0;
		}
	}
	dp[0][0][0] = 1;
	for(ll i = 0; i < Sz(vec); i++){
		solve(i, 0, n, 0);
	}
	cout << setprecision(10) << fixed;
	for(ll i = 0; i < n; i++){
		for(ll j = 1; j < maxn; j++){
			ans[i][j] += ans[i][j - 1];
		}
		for(ll j = 0; j < n; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
 
    return 0;
}