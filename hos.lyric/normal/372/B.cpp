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
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int M, N, Q;
char S[44][44];

int sum[44][44];
int cnt[44][44][44][44];

bool isGood(int xa, int ya, int xb, int yb) {
	return (sum[xa][ya] - sum[xa][yb] - sum[xb][ya] + sum[xb][yb] == 0);
}

int main() {
	int x, y, xx, yy;
	int xa, ya, xb, yb;
	
	for (; ~scanf("%d%d%d", &M, &N, &Q); ) {
		for (x = 0; x < M; ++x) {
			scanf("%s", S[x]);
		}
		for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
			sum[x + 1][y + 1] = sum[x + 1][y] + sum[x][y + 1] - sum[x][y] + ((S[x][y] != '0') ? 1 : 0);
		}
		memset(cnt, 0, sizeof(cnt));
		for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) {
			for (xx = x + 1; xx <= M; ++xx) for (yy = y + 1; yy <= N; ++yy) {
				cnt[x][y][xx + 1][yy + 1] = cnt[x][y][xx + 1][yy] + cnt[x][y][xx][yy + 1] - cnt[x][y][xx][yy] + (isGood(x, y, xx, yy) ? 1 : 0);
			}
		}
		for (; Q--; ) {
			xa = in() - 1;
			ya = in() - 1;
			xb = in();
			yb = in();
			int ans = 0;
			for (x = xa; x < xb; ++x) for (y = ya; y < yb; ++y) {
				ans += cnt[x][y][xb + 1][yb + 1];
			}
			printf("%d\n", ans);
		}
	}
	
	return 0;
}