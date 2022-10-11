//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1100;
const ll maxm = 5e4;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, x, dp[maxm], pd[maxm], ans;

bool vis[maxn];

vector<ll> a, b;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < k; i++){
		cin >> x;
		vis[x] = 1;
	}
	
	for(ll i = 0; i < maxn; i++){
		if(vis[i]){
			if(i < n) a.pb(n - i);
			else if(i > n) b.pb(i - n);
			else{
				cout << 1;
				return 0;
			}
		}
	}
	
	fill(dp, dp + maxm, inf);
	dp[0] = 0;
	
	for(ll i = 0; i < a.size(); i++){
		for(ll j = a[i]; j < maxm; j++){
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
		}
	}
	
	fill(pd, pd + maxm, inf);
	pd[0] = 0;
	
	for(ll i = 0; i < b.size(); i++){
		for(ll j = b[i]; j < maxm; j++){
			pd[j] = min(pd[j], pd[j - b[i]] + 1);
		}
	}
	
	ans = inf;
	
	for(ll i = 0; i < a.size(); i++){
		for(ll j = 0; j < b.size(); j++){
			ans = min(ans, (a[i] + b[j]) / __gcd(a[i], b[j]));
		}
	}
	
	for(ll i = 1; i < maxm; i++){
		ans = min(ans, dp[i] + pd[i]);
	}
	
	if(ans == inf) ans = -1;
	
	cout << ans;
	
	return 0;
}