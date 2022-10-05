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

	ints(n);
	ll cnt[2][2] = {};
	for(int i = 0; i < n; i++) {
		ints(x, y);
		cnt[!!(x & 2)][!!(y & 2)]++;
	}
	ll ans = 0;
	for(int a = 0; a < 2; a++) for(int b = 0; b < 2; b++)
	for(int c = 0; c < 2; c++) for(int d = 0; d < 2; d++)
	for(int e = 0; e < 2; e++) for(int f = 0; f < 2; f++) {
		auto g = [&](int a, int b, int c, int d) { return (a != c) || (b != d); };
		if((g(a, b, c, d) ^ g(a, b, e, f) ^ g(c, d, e, f)) == 0) {
			if(a == c && c == e && b == d && d == f) ans += cnt[a][b] * (cnt[a][b] - 1) * (cnt[a][b] - 2);
			else if(a == c && b == d) ans += cnt[a][b] * (cnt[a][b] - 1) * cnt[e][f];
			else if(a == e && b == f) ans += cnt[a][b] * (cnt[a][b] - 1) * cnt[c][d];
			else if(c == e && d == f) ans += cnt[c][d] * (cnt[c][d] - 1) * cnt[a][b];
			else ans += cnt[a][b] * cnt[c][d] * cnt[e][f];
		}
	}
	writeln(ans / 6);
	return 0;
}