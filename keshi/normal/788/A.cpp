//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], b[maxn], dp[maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll i = 0; i < n - 1; i++){
		b[i] = abs(a[i] - a[i + 1]);
	}
	
	for(ll i = n - 2; i > -1; i--){
		dp[i] = max(b[i], b[i] - b[i + 1] + max(0ll, dp[i + 2]));
	}
	
	cout << *max_element(dp, dp + n - 1);
	
	return 0;
}