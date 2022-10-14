#include<bits/stdc++.h>
#define comp loli
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<20;
int n, m, l[maxn], r[maxn], s[maxn], t[maxn], c[maxn];
vector<int> check[maxn], ev[maxn];
array<ll, 3> ans = {0, 0, 0};
array<int, 2> bad = {-(1<<30), -1};
vector<int> raw;
struct segtree {
	vector<array<int, 2>> t;
	int n;
	segtree(int n = 0) : n(n), t(2*n, bad) {}
	void upd(int p, array<int, 2> val) {
		for(t[p += n] = val; p>>=1;) t[p] = max(t[p*2], t[p*2+1]);
	}
	void upd2(int p, array<int, 2> val) {
		upd(p, max(val, t[p+n]));
	}
	array<int, 2> get(int l, int r) {
		auto ans = bad;
		for(l += n, r += n+1; l < r; l>>=1, r>>=1) {
			if(l&1) ans = max(ans, t[l++]);
			if(r&1) ans = max(ans, t[--r]);
		}
		return ans;
	}
};
set<int> atpos[maxn];
void solve() {
	segtree op(raw.size()), cl(raw.size());
	for(int i = 0; i < raw.size(); i++) {
		for(auto x : ev[i]) {
			if(x >= 0) {
				atpos[i].insert(x);
				op.upd(i, {-raw[i], *atpos[i].begin()});
			} else { x*= -1;
				atpos[l[x]].erase(x);
				if(atpos[l[x]].size())
					op.upd(l[x], {-raw[l[x]], *atpos[l[x]].begin()});
				else
					op.upd(l[x], bad);
				cl.upd2(l[x], {raw[r[x]]-raw[l[x]], x});
				//cout << x << " closes and goes to" << l[x] << endl;
			}
		}
		for(auto x : check[i]) {
			//cout << x << " == " << s[x] << " " << t[x] << endl;
			
			auto f = op.get(0, i);
			f[0] = min(f[0], -raw[s[x]]);
			ll tans = (raw[i] + f[0])*1ll*c[x];
			ans = max(ans, {tans, f[1], x});
		
			f = cl.get(s[x], i);
			//cout << f[0] << " " << f[1] << endl;
			ans = max(ans, {f[0]*1ll*c[x], f[1], x});
			//cout << ans[0] << endl;
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		raw.push_back(l[i]);
		raw.push_back(r[i]);
	}
	for(int i = 1; i <= m; i++) {
		cin >> s[i] >> t[i] >> c[i];
		raw.push_back(s[i]);
		raw.push_back(t[i]);
	}
	sort(all(raw));
	for(int i = 1; i <= n; i++) {
		l[i] = lower_bound(all(raw), l[i]) - raw.begin();
		r[i] = lower_bound(all(raw), r[i]) - raw.begin();
		//cout << l[i] << " " << r[i] << endl;
		ev[l[i]].push_back(i);
		ev[r[i]].push_back(-i);
	}
	for(int i = 1; i <= m; i++) {
		s[i] = lower_bound(all(raw), s[i]) - raw.begin();
		t[i] = lower_bound(all(raw), t[i]) - raw.begin();
		//cout << s[i] << " " << t[i] << endl;
		check[t[i]].push_back(i);
	}
	solve();
	for(int i = 0; i < raw.size(); i++) ev[i].clear(), check[i].clear(),atpos[i].clear();
	for(int i = 1; i <= n; i++) {
		l[i] = raw.size()-1-l[i];
		r[i] = raw.size()-1-r[i];
		swap(l[i], r[i]);
		//cout << l[i] << " " << r[i] << endl;
		ev[l[i]].push_back(i);
		ev[r[i]].push_back(-i);
	}
	for(int i = 1; i <= m; i++) {
		s[i] = raw.size()-1-s[i];
		t[i] = raw.size()-1-t[i];
		swap(s[i], t[i]);
		//cout << s[i] << " " << t[i] << endl;
		check[t[i]].push_back(i);
	}
	reverse(all(raw));
	for(auto &i : raw) i *= -1;
	solve();
	cout << ans[0] << '\n';
	if(ans[0]) cout << ans[1] << " " << ans[2] << '\n';
}