#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, h[maxn], dp[maxn], pd[maxn], ans;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> h[i];
		dp[i] = min(h[i], dp[i - 1] + 1);
	}
	
	for(ll i = n; i > 0; i--){
		pd[i] = min(h[i], pd[i + 1] + 1);
	}
	
	for(ll i = 1; i <= n; i++){
		dp[i] = min(dp[i], pd[i]);
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	
	return 0;
}