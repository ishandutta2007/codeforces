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

const int LIM = 30005;

int N, D;
int P[LIM + 10];

int cs[LIM + 10];
int csSum[LIM + 10];

vector<pint> dp[LIM + 10];

int main() {
	
	
	for (; ~scanf("%d%d", &N, &D); ) {
		for (int n = 0; n < N; ++n) {
			P[n] = in();
		}
		fill(cs, cs + LIM, 0);
		for (int n = 0; n < N; ++n) {
			++cs[P[n]];
		}
		for (int x = LIM; x--; ) {
			csSum[x] = cs[x] + csSum[x + 1];
		}
		for (int x = 0; x < LIM; ++x) {
			dp[x].clear();
		}
		dp[D].emplace_back(D, 0);
		int ans = 0;
		for (int x = 0; x < LIM; ++x) {
			sort(dp[x].begin(), dp[x].end());
			const int sz = dp[x].size();
			for (int i = 0; i < sz; ++i) {
				if (i + 1 < sz && dp[x][i].first == dp[x][i + 1].first) {
					continue;
				}
				const int l = dp[x][i].first;
				const int c = dp[x][i].second + cs[x];
				if (l == 1) {
					chmax(ans, c + csSum[x + 1]);
				} else {
					chmax(ans, c);
					for (int ll = l - 1; ll <= l + 1; ++ll) {
						const int xx = x + ll;
						if (xx < LIM) {
							dp[xx].emplace_back(ll, c);
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}