#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <bitset>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ints(n, m);
	vint xs;
	vector<vpii> seg(n + 1);
	while(m--) {
		ints(i, l, r);
		seg[i].emplace_back(l, r);
		xs.push_back(l);
		xs.push_back(r + 1);
	}
	sort(all(xs));
	xs.erase(unique(all(xs)), xs.end());
	m = xs.size();
	for(int i = 1; i <= n; i++) for(pii &p : seg[i]) {
		p.x = int(lower_bound(all(xs), p.x) - xs.begin());
		p.y = int(lower_bound(all(xs), p.y + 1) - xs.begin()) - 1;
	}
	
	struct Seg {
		vpii d, l;
		int sz;
		Seg(int n) { for(sz = 1; sz < n; sz <<= 1); d = l = vpii(2 * sz); }
		void spr(int x) {
			d[2 * x] = max(d[2 * x], l[x]);
			l[2 * x] = max(l[2 * x], l[x]);
			d[2 * x + 1] = max(d[2 * x + 1], l[x]);
			l[2 * x + 1] = max(l[2 * x + 1], l[x]);
			l[x] = {0, 0};
		}
		void u(int s, int e, pii v, int x, int p, int q) {
			if(e < p || q < s) return;
			if(s <= p && q <= e) {
				d[x] = max(d[x], v);
				l[x] = max(l[x], v);
				return;
			}
			spr(x);
			u(s, e, v, 2 * x, p, (p + q) >> 1);
			u(s, e, v, 2 * x + 1, (p + q + 2) >> 1, q);
			d[x] = max(d[2 * x], d[2 * x + 1]);
		}
		void u(int s, int e, pii v) { u(s, e, v, 1, 0, sz - 1); }
		pii g(int s, int e, int x, int p, int q) {
			if(e < p || q < s) return {0, 0};
			if(s <= p && q <= e) return d[x];
			spr(x);
			return max(g(s, e, 2 * x, p, (p + q) >> 1), g(s, e, 2 * x + 1, (p + q + 2) >> 1, q));
		}
		pii g(int s, int e) { return g(s, e, 1, 0, sz - 1); }
	} S(m);

	vint d(n + 1), prv(n + 1);
	for(int i = 1; i <= n; i++) {
		for(pii &p : seg[i]) {
			pii t = S.g(p.x, p.y);
			if(t.x + 1 > d[i]) {
				d[i] = t.x + 1;
				prv[i] = t.y;
			}
		}
		for(pii &p : seg[i]) S.u(p.x, p.y, {d[i], i});
	}
	
	int t = int(max_element(all(d)) - d.begin());
	set<int> s;
	for(int i = 1; i <= n; i++) s.insert(i);
	while(t) {
		s.erase(t);
		t = prv[t];
	}	
	cout << s.size() << '\n';
	for(int i : s) cout << i << ' ';
	cout << '\n';
	
	return 0;
}