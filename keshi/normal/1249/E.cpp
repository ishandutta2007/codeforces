//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, c, a[maxn], b[maxn], dp[maxn], pd[maxn];

int main(){
	fast_io;
	
	cin >> n >> c;
	
	for(ll i = 1; i < n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i < n; i++){
		cin >> b[i];
	}
	
	cout << "0 ";
	
	dp[1] = inf;
	
	for(ll i = 2; i <= n; i++){
		dp[i] = min(dp[i - 1], pd[i - 1] + c) + b[i - 1];
		pd[i] = min(dp[i - 1], pd[i - 1]) + a[i - 1];
		cout << min(dp[i], pd[i]) << " ";
	}
	
	
	return 0;
}