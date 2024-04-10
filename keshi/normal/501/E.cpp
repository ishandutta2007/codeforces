//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, a[maxn], c[maxn], ans;
vector<ll> vec[maxn];

void solve(){
	for(ll i = 1; i <= n; i++){
		vec[i].clear();
	}
	for(ll i = 0; i < n; i++){
		vec[a[i]].pb(i);
	}
	ll r = (n - 1) / 2;
	bool f = 1;
	for(ll i = 1; i <= n; i++){
		if(vec[i].empty()) continue;
		if(Sz(vec[i]) & 1){
			if(vec[i][Sz(vec[i]) / 2] != n / 2) f = 0;
		}
		else{
			if(vec[i][Sz(vec[i]) / 2] < n / 2) f = 0;
			if(vec[i][Sz(vec[i]) / 2 - 1] >= n / 2) f = 0;
		}
		r = max(r, vec[i][(Sz(vec[i]) - 1) / 2]);
	}
	ans += n - r - 1;
	for(ll i = 0; i < n - 1 - i; i++){
		if(a[i] != a[n - 1 - i]) break;
		ans += (n - 1 - i) - r - 1;
	}
	if(f == 0) return;
	ll R = -1;
	for(ll i = 0; i < n - 1 - i; i++){
		if(a[i] != a[n - 1 - i]) R = i;
	}
	if(R == -1){
		ans += ((n - 1) / 2) * ((n - 1) / 2 + 1) / 2;
		return;
	}
	ll L = -1;
	for(ll i = n / 2; i--;){
		if(a[i] != a[n - 1 - i]) L = i;
	}
	ans += (L + 1) * ((n - 1) / 2 - R);
}

int main(){
	fast_io;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		c[a[i]]++;
	}
	ll x = 0;
	for(ll i = 1; i <= n; i++){
		x += c[i] & 1;
	}
	if(x > 1){
		cout << 0;
		return 0;
	}
	for(ll i = 0; i <= n - i - 1; i++){
		ans++;
		if(a[i] != a[n - 1 - i]) break;
	}
	solve();
	reverse(a, a + n);
	solve();
	cout << ans;
	
	
	return 0;
}