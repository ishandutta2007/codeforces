//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e3 + 100;
const ll maxm = 5e6;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], b[maxn], ps1[maxn], ps2[maxn], mx[maxm], x, y, ans;

ll cal(ll x1, ll x2, ll y1, ll y2){
	return (ps1[x2] - ps1[x1 - 1]) * (ps2[y2] - ps2[y1 - 1]);
}

int main(){
	fast_io;
	
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		ps1[i] = ps1[i - 1] + a[i];
	}
	for(ll i = 1; i <= m; i++){
		cin >> b[i];
		ps2[i] = ps2[i - 1] + b[i];
	}
	cin >> x;
	for(ll i = 0; i < n; i++){
		for(ll j = i + 1; j <= n; j++){
			mx[ps1[j] - ps1[i]] = max(mx[ps1[j] - ps1[i]], j - i);
		}
	}
	for(ll i = 1; i < maxm; i++){
		mx[i] = max(mx[i - 1], mx[i]);
	}
	
	
	for(ll i = 0; i < m; i++){
		for(ll j = i + 1; j <= m; j++){
			y = x / (ps2[j] - ps2[i]);
			if(y >= maxm) y = maxm - 1;
			ans = max(ans, (j - i) * mx[y]);
		}
	}
	cout << ans;
	
	return 0;
}