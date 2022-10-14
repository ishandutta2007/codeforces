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
int n, m;
vi a, b;
ll res[maxn];
bool can(ll mn, ll k) {
	if(mn > 0) return 0;
	multiset<ll> c;
	ll sm = 0;
	for(int i = 0; i < n; i++) {
		sm += a[i];
		c.insert(a[i]);
		while(sm < mn) {
			if(--k < 0) return false;
			sm -= *c.begin();
			c.erase(c.begin());
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	a.resize(n);
	for(auto &i : a) cin >> i;
	b.resize(m+1);
	b[0] = (1ll<<60);
	for(int i = 1; i <= m; i++) cin >> b[i];
	vi tb = b;
	for(auto &i : b) i*=-1;
	sort(all(b));
	for(int i = 0; i <= n; i++) {
		res[i] = i?res[i-1]:0;
		for(ll x = 1ll<<42; x>>=1;) if(res[i]+x<b.size()&&can(b[res[i]+x], i)) res[i] += x;
	}
	for(int i = 0; i <= n; i++) res[i] = b[res[i]];
	for(ll t, i = 0; i < m; i++) {
		t = tb[i+1];
		ll x = 0;
		for(int i = 1<<15; i>>=1;) if(res[x+i]+t<0) x+=i;
		cout << (res[0]+t>=0?0:x+1) << '\n';
	}
}