//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], s;
ld dp[2][maxn], ps[2][maxn], ans;

int main(){
	fast_io;
	
	cout << setprecision(20) << fixed;
	
	cin >> n >> m;
	
	if(m == 1){
		cout << 1;
		return 0;
	}
	
	dp[0][0] = 1;
	fill(ps[0], ps[0] + maxn, 1);
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		for(ll j = 0; j < maxn; j++){
			dp[i % 2][j] = ((j - 1 >= 0 ? ps[1 - i % 2][j - 1] : 0.0) - (j - m - 1 >= 0 ? ps[1 - i % 2][j - m - 1] : 0.0) - (j - a[i] >= 0 ? dp[1 - i % 2][j - a[i]] : 0.0)) / (m - 1);
			ps[i % 2][j] = (j - 1 >= 0 ? ps[i % 2][j - 1] : 0.0) + dp[i % 2][j];
		}
		s += a[i];
	}
	ans = 1;
	for(ll i = 0; i < s; i++){
		ans += dp[n % 2][i] * (m - 1);
	}
	
	cout << ans;
	
	return 0;
}