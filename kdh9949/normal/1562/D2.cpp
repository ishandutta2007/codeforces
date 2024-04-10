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

const int K = 300010;
struct Seg {
	int d[K], dd[K];
	vint a[2 * K];
	void i(int n, const string &s) {
		for(int i = 0; i < n; i++) {
			dd[i + 1] = d[i + 1] = (i & 1 ? 1 : -1) * (s[i] == '+' ? 1 : -1);
			d[i + 1] += d[i];
		}
		for(int i = 1; i <= n; i++) a[d[i] + K].push_back(i);
	}
	int g(int s, int e) { return d[e] - d[s - 1]; }
	int f(int s, int x) {
		auto it = lower_bound(all(a[x + K]), s);
		if(it == a[x + K].end()) return -1;
		return *it;
	}
	void end(int n) {
		for(int i = 1; i <= n; i++) a[d[i] + K] = vint();
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
			if(t == 0) { cout << "0\n\n"; continue; }
			if(t & 1) {
				cout << "1\n";
				int target = S.d[x - 1] + ((t > 0) - (t < 0)) * (abs(t) / 2 + 1);
				cout << S.f(x, target) << '\n';
			}
			else {
				cout << "2\n";
				t -= S.dd[y];
				int target = S.d[x - 1] + ((t > 0) - (t < 0)) * (abs(t) / 2 + 1);
				cout << S.f(x, target) << ' ' << y << '\n';
			}
		}
		S.end(n);
	}

	return 0;
}