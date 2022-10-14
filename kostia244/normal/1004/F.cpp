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
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<17, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int x;
struct node {
	vpi pref, suf;
	ll ans = 0, sz = 0;
	node() {}
	node(int a) { pref.pb({a, 1}), suf.pb({a, 1}), ans = a>=x, sz = 1;}
	void print() const {
		cout << ans << ":::\n";
		for(auto i : pref) cout << "( " << i.first << ", " << i.second << ") ";cout << '\n';
		for(auto i : suf) cout << "( " << i.first << ", " << i.second << ") ";cout << '\n';
	}
};
node t[maxn<<1];
struct segtree {
	void merge(vpi &a, const vpi &b) {
		for(auto &i : b) {
			if(!a.empty()&&(a.back().first|i.first)==a.back().first) a.back().second += i.second;
			else a.pb({(a.empty()?0:a.back().first)|i.first, i.second});
		}
	}
	node merge(const node &a, const node &b) {
		node res;
		res.ans = a.ans+b.ans;
		res.sz = a.sz+b.sz;
		
		int j = 0, cnt = a.sz;
		for(int i = b.pref.size(); cnt && i--;) {
			while(j < a.suf.size() && (b.pref[i].first|a.suf[j].first) < x) cnt -= a.suf[j++].second;
			res.ans += cnt * 1ll * b.pref[i].second;
		}
		
		res.pref = a.pref, merge(res.pref, b.pref);
		res.suf = b.suf, merge(res.suf, a.suf);
		
		return res;
	}
	
	int n;
	
	void init(vi &a) {
		n = a.size();
		for(int i = 0; i < n; i++) t[n+i] = node(a[i]);
		for(int i = n-1; i; i--) t[i] = merge(t[i<<1], t[i<<1|1]);
	}
	void upd(int p, node v) {
		for(t[p+=n]=v;p>>=1;) t[p] = merge(t[p<<1], t[p<<1|1]);
	}
	ll get(int l, int r) {
		node al, ar;
		for(l+=n, r+=n+1; l < r; l >>= 1, r >>= 1) {
			if(l&1) al = merge(al, t[l++]);
			if(r&1) ar = merge(t[--r], ar);
		}
		return merge(al, ar).ans;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m >> x;
	vi a(n);
	for(auto &i : a) cin >> i;
	segtree st;
	st.init(a);
	while(m--) {
		int t, l, r;
		cin >> t;
		if(t == 1) {
			cin >> l >> r, l--;
			st.upd(l, node(r));
		} else {
			cin >> l >> r, l--, r--;
			cout << st.get(l, r) << '\n';
		}
	}
	return 0;
}