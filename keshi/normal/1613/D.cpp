//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll t, n, a[maxn], dp[maxn], dd[maxn], pp[maxn];

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		fill(dp, dp + n + 10, 0);
		fill(dd, dd + n + 10, 0);
		fill(pp, pp + n + 10, 0);
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		ll c = 0;
		for(ll i = n; i--;){
			dd[a[i]] += dd[a[i]] + 1 + (a[i] - 2 >= 0 ? pp[a[i] - 2] : 0);
			pp[a[i]] += pp[a[i]] + 1 + dd[a[i] + 2];
			dp[a[i]] += dp[a[i]] + 1 + dp[a[i] + 1] + dd[a[i] + 2];
			dp[a[i]] %= mod;
			dd[a[i]] %= mod;
			pp[a[i]] %= mod;
			if(a[i] == 1) c = (c * 2 + 1) % mod;
		}
		cout << (dp[0] + c) % mod << "\n";
	}
	
	return 0;
}