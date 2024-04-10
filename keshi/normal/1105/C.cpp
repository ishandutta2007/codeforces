//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, l, r, a[3], dp[2][3];

int main(){
	fast_io;
	
	cin >> n >> l >> r;
	
	while((r - l + 1) % 3){
		a[r % 3]++;
		r--;
	}
	a[0] += (r - l + 1) / 3;
	a[1] += (r - l + 1) / 3;
	a[2] += (r - l + 1) / 3;
	
	dp[0][0] = 1;
	for(ll i = 1; i <= n; i++){
		dp[i % 2][0] = (dp[(i - 1) % 2][0] * a[0] + dp[(i - 1) % 2][1] * a[2] + dp[(i - 1) % 2][2] * a[1]) % mod;
		dp[i % 2][1] = (dp[(i - 1) % 2][0] * a[1] + dp[(i - 1) % 2][1] * a[0] + dp[(i - 1) % 2][2] * a[2]) % mod;
		dp[i % 2][2] = (dp[(i - 1) % 2][0] * a[2] + dp[(i - 1) % 2][1] * a[1] + dp[(i - 1) % 2][2] * a[0]) % mod;
	}
	
	cout << dp[n % 2][0];
	
	return 0;
}