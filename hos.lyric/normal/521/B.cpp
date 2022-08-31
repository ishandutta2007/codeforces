#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstdint>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define mp make_pair

template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template <typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template <typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

const Int MO = 1000000009;

int N;
int X[100010], Y[100010];

map<pint, int> tr;
int nei[100010][5][3];

bool is[100010];

set<int> cands;
bool on[100010];

bool canRemove(int u) {
#define has(e,f) is[nei[u][e][f]]
	if (has(1, 2) && !has(0, 1) && !has(1, 1)) return false;
	if (has(2, 2) && !has(1, 1) && !has(3, 1)) return false;
	if (has(3, 2) && !has(3, 1) && !has(4, 1)) return false;
	return true;
#undef has
}

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int u = 0; u < N; ++u) {
			X[u] = in();
			Y[u] = in();
		}
		tr.clear();
		for (int u = 0; u < N; ++u) {
			tr[mp(X[u], Y[u])] = u;
		}
		for (int u = 0; u < N; ++u) {
			for (int e = 0; e < 5; ++e) for (int f = 0; f < 3; ++f) {
				auto it = tr.find(mp(X[u] - 2 + e, Y[u] - 1 + f));
				nei[u][e][f] = (it != tr.end()) ? it->second : N;
			}
		}
		fill(is, is + N, true);
		is[N] = false;
		
		cands.clear();
		fill(on, on + N, false);
		for (int u = 0; u < N; ++u) {
			if (canRemove(u)) {
				cands.insert(u);
				on[u] = true;
			}
		}
		
		Int ans = 0;
		for (int turn = 0; turn < N; ++turn) {
			assert(!cands.empty());
			int u = -1;
			switch (turn % 2) {
				case 0: {
					u = *--cands.end();
				} break;
				case 1: {
					u = *cands.begin();
				} break;
				default: assert(false);
			}
			assert(is[u]);
			ans = (ans * N + u) % MO;
			cands.erase(u);
			on[u] = false;
			is[u] = false;
			for (int e = 0; e < 5; ++e) for (int f = 0; f < 3; ++f) {
				const int v = nei[u][e][f];
				if (is[v]) {
					const bool res = canRemove(v);
					if (on[v] != res) {
						if (res) {
							cands.insert(v);
						} else {
							cands.erase(v);
						}
						on[v] = res;
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}