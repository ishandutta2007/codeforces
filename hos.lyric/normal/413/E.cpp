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
template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

const int INF = 1001001001;

int N, M;
char A[2][200010];

int segN;
int seg[800010][2][2];

void mul(int f[2][2], int g[2][2], int ret[2][2]) {
	int tmp[2][2] = { { INF, INF }, { INF, INF } };
	for (int x = 0; x < 2; ++x) for (int z = 0; z < 2; ++z) for (int y = 0; y < 2; ++y) {
		chmin(tmp[x][y], f[x][z] + 1 + g[z][y]);
	}
	for (int x = 0; x < 2; ++x) for (int y = 0; y < 2; ++y) {
		ret[x][y] = tmp[x][y];
	}
}

void rangeProduct(int a, int b, int ret[2][2]) {
	int retL[2][2] = { { -1, INF }, { INF, -1 } };
	int retR[2][2] = { { -1, INF }, { INF, -1 } };
	for (a += segN, b += segN; a <= b; a >>= 1, b >>= 1) {
		if ( a & 1) mul(retL, seg[a++], retL);
		if (~b & 1) mul(seg[b--], retR, retR);
	}
	mul(retL, retR, ret);
}

int main() {
	
	
	for (; ~scanf("%d%d", &N, &M); ) {
		scanf("%s%s", A[0], A[1]);
		for (segN = 2; segN < N; segN <<= 1);
		for (int a = 0; a < segN * 2; ++a) {
			for (int x = 0; x < 2; ++x) for (int y = 0; y < 2; ++y) {
				seg[a][x][y] = INF;
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int x = 0; x < 2; ++x) for (int y = 0; y < 2; ++y) {
				seg[segN + i][x][y] = (A[x][i] == '.' && A[y][i] == '.') ? abs(x - y) : INF;
			}
		}
		for (int a = segN; --a; ) {
			mul(seg[a << 1], seg[a << 1 | 1], seg[a]);
		}
// for(int a=1;a<segN*2;++a){cout<<a<<": ";for(int x=0;x<2;++x)for(int y=0;y<2;++y)cout<<seg[a][x][y]<<" ";cout<<endl;}
		for (; M--; ) {
			int u = in() - 1;
			int v = in() - 1;
			if (u % N > v % N) {
				swap(u, v);
			}
			int res[2][2];
			rangeProduct(u % N, v % N, res);
			int ans = res[u / N][v / N];
			printf("%d\n", (ans >= INF) ? -1 : ans);
		}
	}
	
	return 0;
}