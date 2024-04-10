//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 220;
const ll maxm = 1100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, k, a[maxn], dp[2][maxn][maxm];

int main(){
    fast_io;

	cin >> n >> k;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	dp[0][0][0] = 1;
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j <= n; j++){
			for(ll o = 0; o <= k; o++){
				ll& ans = dp[i & 1][j][o];
				ans = 0;
				if(o >= j * (a[i] - a[i - 1])){
					ans += (j + 1) * dp[i - 1 & 1][j][o - j * (a[i] - a[i - 1])];
				}
				if(o >= (j + 1) * (a[i] - a[i - 1])){
					ans += (j + 1) * dp[i - 1 & 1][j + 1][o - (j + 1) * (a[i] - a[i - 1])];
				}
				if(j > 0 && o >= (j - 1) * (a[i] - a[i - 1])){
					ans += dp[i - 1 & 1][j - 1][o - (j - 1) * (a[i] - a[i - 1])];
				}
				ans %= mod;
			}
		}
	}
	ll ans = 0;
	for(ll i = 0; i <= k; i++){
		ans = (ans + dp[n & 1][0][i]) % mod;
	}
	cout << ans;

    return 0;
}