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

const int sz = 524288;
struct Seg {
	int d[2 * sz];
	void i(int n, const string &s) {
		for(int i = 0; i < n; i++) d[i + 1 + sz] = (i & 1 ? 1 : -1) * (s[i] == '+' ? 1 : -1);
		for(int i = sz - 1; i; i--) d[i] = d[i << 1] + d[i << 1 | 1];
	}
	int g(int s, int e) {
		int r = 0;
		for(s += sz, e += sz; s <= e; s >>= 1, e >>= 1) {
			if(s & 1) r += d[s++];
			if(~e & 1) r += d[e--];
		}
		return r;
	}
} S;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ints(t);
	while(t--) {
		ints(n, q);
		strs(s);
		S.i(n, s);
		while(q--) {
			ints(x, y);
			int t = S.g(x, y);
			if(t != 0) t = 1 + (t % 2 == 0);
			cout << t << '\n';
		}
	}

	return 0;
}