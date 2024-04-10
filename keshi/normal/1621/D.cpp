//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 600;
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

ll q, n, a[maxn][maxn];

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		cin >> n;
		for(ll i = 0; i < n + n; i++){
			for(ll j = 0; j < n + n; j++){
				cin >> a[i][j];
			}
		}
		ll x = 0;
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				x += a[i][j] + a[n + i][n + j];
			}
		}
		ll ans = inf;
		ans = min(ans, x + a[n - 1][n]);
		ans = min(ans, x + a[n][n - 1]);
		ans = min(ans, x + a[n - 1][n + n - 1]);
		ans = min(ans, x + a[n + n - 1][n - 1]);
		ans = min(ans, x + a[0][n]);
		ans = min(ans, x + a[n][0]);
		ans = min(ans, x + a[0][n + n - 1]);
		ans = min(ans, x + a[n + n - 1][0]);
		cout << ans << "\n";
	}
	
	return 0;
}