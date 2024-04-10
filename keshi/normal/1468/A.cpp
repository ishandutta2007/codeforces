//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int t, n, a[maxn], fen[maxn], dp[maxn];
vector<int> vec, g[maxn];

void upd(int x, int y){
	for(x += 5; x < maxn; x += x & -x){
		fen[x] = max(fen[x], y);
	}
}
int get(int x){
	int y = 0;
	for(x += 5; x > 0; x -= x & -x){
		y = max(y, fen[x]);
	}
	return y;
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i <= n; i++){
			g[i].clear();
		}
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vec.clear();
		a[n] = n + 10;
		vec.pb(n);
		for(int i = n; i--;){
			while(a[vec.back()] <= a[i]) vec.pop_back();
			g[vec.back()].pb(i);
			vec.pb(i);
		}
		memset(fen, 0, sizeof fen);
		int mx = -1, ans = 0;
		for(int i = 0; i < n; i++){
			dp[i] = get(a[i]) + 1;
			if(mx > a[i]) dp[i] = max(dp[i], 2);
			mx = max(mx, a[i]);
			upd(a[i], dp[i]);
			ans = max(ans, dp[i]);
			for(int j : g[i]){
				upd(a[j], dp[j] + 1);
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}