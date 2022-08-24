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

int M, N;
char A[110][110];
int V;

bool vis[110][110];
int dfs(int x, int y) {
	if (!(0 <= x && x < M && 0 <= y && y < N)) return 0;
	if (A[x][y] != '#') return 0;
	if (vis[x][y]) return 0;
	vis[x][y] = 1;
	int ret = 1;
	int h;
	for (h = 0; h < 4; ++h) {
		ret += dfs(x + dx[h], y + dy[h]);
	}
	return ret;
}

int main() {
	int x, y;
	int h, xx, yy;
	
	for (; ~scanf("%d%d", &M, &N); ) {
		for (x = 0; x < M; ++x) {
			scanf("%s", A[x]);
		}
		V = 0;
		for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (A[x][y] == '#') {
			++V;
		}
		int ans = V;
		for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (A[x][y] == '#') {
			int tmp = 0;
			for (h = 0; h < 4; ++h) {
				xx = x + dx[h];
				yy = y + dy[h];
				if (0 <= xx && xx < M && 0 <= yy && yy < N) if (A[xx][yy] == '#') {
					++tmp;
				}
			}
			if (1 + tmp < V) {
				chmin(ans, tmp);
			}
		}
		for (x = 0; x < M; ++x) for (y = 0; y < N; ++y) if (A[x][y] == '#') {
			A[x][y] = '?';
			for (xx = 0; xx < M; ++xx) for (yy = 0; yy < N; ++yy) if (A[xx][yy] == '#') {
				memset(vis, 0, sizeof(vis));
				if (dfs(xx, yy) < V - 1) {
cerr<<"single "<<x<<" "<<y<<endl;
					chmin(ans, 1);
				}
				goto done;
			}
		done:;
			A[x][y] = '#';
		}
		if (ans >= V - 1) {
			ans = -1;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}