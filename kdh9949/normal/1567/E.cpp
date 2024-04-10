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

ll F(ll x) { return x * (x + 1) / 2; }

const int sz = 262144;
struct Seg {
	struct Info { int x, y; ll ans, l, r; } d[2 * sz];
	int v[sz];
	Info mrg(const Info &a, const Info &b) {
		if(a.x < 0) return b;
		if(b.x < 0) return a;
		if(v[a.y] > v[b.x]) return (Info){a.x, b.y, a.ans + b.ans, a.l, b.r};
		return (Info){
			a.x, b.y,
			a.ans + b.ans - F(a.r) - F(b.l) + F(a.r + b.l),
			a.l + (a.y - a.x + 1 == a.l ? b.l : 0),
			b.r + (b.y - b.x + 1 == b.r ? a.r : 0)
		};
	}
	void i(int n, const vint &a) {
		for(int i = 1; i <= n; i++) v[i] = a[i];
		for(int i = sz; i < 2 * sz; i++) d[i] = (Info){i - sz, i - sz, 1, 1, 1};
		for(int i = sz - 1; i; i--) d[i] = mrg(d[i << 1], d[i << 1 | 1]);
	}
	void u(int x, int y) {
		v[x] = y;
		for(x = (x + sz) >> 1; x; x >>= 1) d[x] = mrg(d[x << 1], d[x << 1 | 1]);
	}
	ll g(int s, int e) {
		Info li = (Info){-1, -1, -1, -1, -1};
		Info ri = li;
		for(s += sz, e += sz; s <= e; s >>= 1, e >>= 1) {
			if(s & 1) li = mrg(li, d[s++]);
			if(~e & 1) ri = mrg(d[e--], ri);
		}
		return mrg(li, ri).ans;
	}
} S;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ints(n, q);
	vint a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	S.i(n, a);
	
	while(q--) {
		ints(t, x, y);
		if(t == 1) S.u(x, y);
		else cout << S.g(x, y) << '\n';
	}
	
	return 0;
}