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

const int sz = 131072;
struct Seg {
	struct Dat { ll a, m, ans; } d[2 * sz];
	Dat mrg(Dat p, Dat q) { return (Dat){p.a + q.a, min(p.m, p.a + q.m), max(p.ans, p.a + q.ans)}; }
	void i(int n, const vll &a) {
		for(int i = 1; i <= n; i++) d[i + sz] = (Dat){a[i], min(0LL, a[i]), max(0LL, a[i])};
		for(int i = sz - 1; i; i--) d[i] = mrg(d[i << 1], d[i << 1 | 1]);
	}
	ll g(int s, int e) {
		Dat fr = {0, 0}, rr = {0, 0};
		for(s += sz, e += sz; s <= e; s >>= 1, e >>= 1) {
			if(s & 1) fr = mrg(fr, d[s++]);
			if(~e & 1) rr = mrg(d[e--], rr);
		}
		fr = mrg(fr, rr);
		return (fr.a == 0 && fr.m == 0 ? fr.ans : -1LL);
	}
} S;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ints(n, q);
	vll a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		lls(x);
		a[i] = x - a[i];
	}
	S.i(n, a);
	while(q--) {
		ints(x, y);
		cout << S.g(x, y) << '\n';
	}
	return 0;
}