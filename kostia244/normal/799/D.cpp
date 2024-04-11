#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
//const ll mod = 1e9 + 7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll a, b, w, h, n;
vi v;

bool check(ll h, ll w) {
	return (h>=a&&w>=b)||(h>=b&&w>=a);
}

ll mm(ll a, ll b) {
	if(LLONG_MAX/a < b) return 1e17;
	return a*b;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> a >> b >> h >> w >> n;
	v.resize(n);
	for(auto &i : v) cin >> i;
	sort(all(v), greater<ll>());
	if(check(h, w)) return cout << 0, 0;
	ll mul = 1;
	set<ll> bp, cbp;
	bp.insert(1);
	for(int i = 0; i < n; i++) {
		mul = mm(mul, v[i]);
		if(mul > 1e15) return cout << i+1, 0;
		for(auto j : bp)
				cbp.insert(min(100000000ll, j*v[i]));
		for(auto j : bp)
			cbp.insert(j);
		bp.swap(cbp);
		for(auto j : bp) {
			if(check(mm(j, h), mm(mul/j, w)))
				return cout << i+1, 0;
		}
	}
	cout << -1;
}