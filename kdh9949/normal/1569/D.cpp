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
#include <chrono>
#include <random>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

const int M = 998244353;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ints(t);
	while(t--) {
		ints(n, m, q);
		vint xs(n), ys(m);
		for(int i = 0; i < n; i++) cin >> xs[i];
		for(int i = 0; i < m; i++) cin >> ys[i];
		vint xc(n), yc(m);
		map<pii, int> xm, ym;
		ll ans = 0;
		while(q--) {
			ints(x, y);
			int onx = binary_search(all(xs), x);
			int ony = binary_search(all(ys), y);
			if(!onx) {
				int mx = int(lower_bound(all(xs), x) - xs.begin());
				int my = int(lower_bound(all(ys), y) - ys.begin());
				ans += xc[mx] - xm[pii(mx, my)];
				xc[mx]++;
				xm[pii(mx, my)]++;
			}
			else if(!ony) {
				int mx = int(lower_bound(all(xs), x) - xs.begin());
				int my = int(lower_bound(all(ys), y) - ys.begin());
				ans += yc[my] - ym[pii(mx, my)];
				yc[my]++;
				ym[pii(mx, my)]++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}