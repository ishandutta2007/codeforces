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

ll n, k, p, a[maxn], b[maxn], x, ans;

int main(){
	fast_io;
	
	cin >> n >> k >> p;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	sort(a, a + n);
	
	for(ll i = 0; i < k; i++){
		cin >> b[i];
	}
	
	sort(b, b + k);
	
	ans = inf;
	
	for(ll i = 0; i + n <= k; i++){
		x = 0;
		for(ll j = 0; j < n; j++){
			x = max(x, abs(a[j] - b[i + j]) + abs(b[i + j] - p));
		}
		ans = min(ans, x);
	}
	
	cout << ans;
	
	return 0;
}