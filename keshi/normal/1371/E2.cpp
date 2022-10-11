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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, p, a[maxn], x, y, vis[maxn];
vector<ll> ans;

int main(){
	fast_io;
	
	cin >> n >> p;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n, greater<ll>());
	for(ll i = 0; i < n; i++){
		x = max(x, a[i] + i - n);
		y = ((a[i] + i - n) % p + p) % p;
		vis[y] = max(vis[y], a[i]);
	}
	y = inf;
	for(ll i = 1; p * i <= n; i++){
		y = min(y, a[n - p * i]);
	}
	for(ll i = x + 1; i < y; i++){
		if(vis[i % p] < i) ans.pb(i);
	}
	cout << ans.size() << '\n';
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}