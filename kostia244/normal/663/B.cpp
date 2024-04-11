#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<18, mod = 1e9 + 7 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	string s;
	cin >> s;
	ll x = stoi(s.substr(4));
	ll ans = 0;
    ll p = 10, l = 1989, r = 1999;
	for(ll i = 0; i+5 < s.size(); i++) {
	    p *= 10;
	    l = r;
	    r += p;
	}
	ll tl = l + (p - l%p)%p;
	ll a = tl-p+x%p;
	if(a>=l) cout << a;
	else cout << a+p;
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}