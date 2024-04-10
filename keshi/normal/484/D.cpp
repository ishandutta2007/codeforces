//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], dp[maxn], mx, mn;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	mx = -a[0];
	mn = a[0];
	
	for(ll i = 0; i < n; i++){
		dp[i] = max(a[i] + mx, mn - a[i]);
		mx = max(mx, dp[i] - a[i + 1]);
		mn = max(mn, dp[i] + a[i + 1]);
	}
	
	cout << dp[n - 1];
	
	return 0;
}