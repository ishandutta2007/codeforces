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

	ints(n, q);

	const static ll M = ll(1e9) + 7;
	vll fa(3 * n + 2), ifa(3 * n + 2);
	const auto pw = [&](ll x, ll k) {
		ll r = 1;
		for(ll t = x; k; k >>= 1, t = t * t % M) if(k & 1) r = r * t % M;
		return r;
	};
	fa[0] = 1;
	for(int i = 1; i <= 3 * n + 1; i++) fa[i] = fa[i - 1] * i % M;
	ifa[3 * n + 1] = pw(fa[3 * n + 1], M - 2);
	for(int i = 3 * n; i >= 0; i--) ifa[i] = ifa[i + 1] * (i + 1) % M;
	const auto binom = [&](int n, int r) {
		if(n < 0 || r < 0 || n < r) return 0LL;
		return fa[n] * ifa[r] % M * ifa[n - r] % M;
	};
	
	vll A(3 * n + 1), B(3 * n + 1), C(3 * n + 1);
	C[3 * n] = 1;
	for(int x = 3 * n - 1; x >= 1; x--) {
		A[x] = (B[x + 1] - A[x + 1] + M) % M;
		B[x] = (C[x + 1] - B[x + 1] + M) % M;
		C[x] = (binom(3 * n + 1, x + 1) - C[x + 1] + A[x + 1] + M) % M;
	}

	while(q--) {
		ints(x);
		writeln(C[x]);
	}
	return 0;
}