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

	ints(t);
	while(t--) {
		ints(n);
		vll a(n);
		for(ll &x : a) cin >> x;
		if(n == 1) { writeln(1); continue; }
		for(int i = 1; i < n; i++) a[i - 1] = abs(a[i - 1] - a[i]);
		const function<int(int, int)> f = [&](int l, int r) -> int {
			if(l == r) return (a[l] != 1);
			int m = (l + r) >> 1;
			int res = max(f(l, m), f(m + 1, r));
			vpli lv, rv;
			lv.emplace_back(a[m], m);
			for(int i = m - 1; i >= l; i--) {
				ll g = gcd(a[i], lv.back().x);
				if(g == lv.back().x) lv.back().y = i;
				else lv.emplace_back(g, i);
			}
			rv.emplace_back(a[m + 1], m + 1);
			for(int i = m + 2; i <= r; i++) {
				ll g = gcd(a[i], rv.back().x);
				if(g == rv.back().x) rv.back().y = i;
				else rv.emplace_back(g, i);
			}
			for(pli &p : lv) for(pli &q : rv) if(gcd(p.x, q.x) != 1) res = max(res, q.y - p.y + 1);
			return res;
		};
		writeln(f(0, n - 2) + 1);
	}
	
	return 0;
}