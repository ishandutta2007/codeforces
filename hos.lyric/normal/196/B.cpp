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

int dx[] = { 1, 0, -1, 0, };
int dy[] = { 0, 1, 0, -1, };

#define MAX 1510

int M, N;
char A[MAX][MAX];
bool vis[MAX][MAX];
pint pos[MAX][MAX];
int que[MAX * MAX * 8], *qb, *qe;

int main() {
	int x, y;
	int h;
	int xx, yy;
	int rx, ry;
	
	for (; ~scanf("%d%d", &M, &N); ) {
		for (x = 0; x < M; ++x) {
			scanf("%s", A[x]);
		}
		qb = qe = que;
		memset(vis, 0, sizeof(vis));
		for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (A[x][y] == 'S') {
			vis[x][y] = 1;
			pos[x][y] = mp(x, y);
			*qe++ = x;
			*qe++ = y;
		}
		bool ans = 0;
		for (; qb != qe; ) {
			x = *qb++;
			y = *qb++;
			for (h = 0; h < 4; ++h) {
				xx = x + dx[h];
				yy = y + dy[h];
				rx = (xx % M + M) % M;
				ry = (yy % N + N) % N;
				if (A[rx][ry] != '#') {
					if (vis[rx][ry]) {
						if (pos[rx][ry] != mp(xx, yy)) {
							ans = 1;
							goto found;
						}
					} else {
						vis[rx][ry] = 1;
						pos[rx][ry] = mp(xx, yy);
						*qe++ = xx;
						*qe++ = yy;
					}
				}
			}
		}
	found:;
		puts(ans ? "Yes" : "No");
	}
	
	return 0;
}