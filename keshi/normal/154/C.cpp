//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
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

ll n, m, p[maxn], h[maxn], ans;
map<ll, ll> cnt, cnt2;

int main(){
	fast_io;
	
	cin >> n >> m;
	p[0] = 1;
	for(ll i = 1; i <= n; i++){
		p[i] = p[i - 1] * 3;
	}
	for(ll i = 0; i < m; i++){
		ll v, u;
		cin >> v >> u;
		h[v] += p[u];
		h[u] += p[v];
	}
	for(ll i = 1; i <= n; i++){
		p[i] += h[i];
	}
	sort(h + 1, h + n + 1);
	sort(p + 1, p + n + 1);
	ll x = 0;
	for(ll i = 2; i <= n; i++){
		if(h[i] == h[i - 1]) x++;
		else x = 0;
		ans += x;
	}
	x = 0;
	for(ll i = 2; i <= n; i++){
		if(p[i] == p[i - 1]) x++;
		else x = 0;
		ans += x;
	}
	cout << ans;
	
	return 0;
}