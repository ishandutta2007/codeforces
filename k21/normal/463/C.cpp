#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXN = 2100;

int N;
ll A[MAXN][MAXN];

ll diag1[MAXN][MAXN];
ll diag2[MAXN][MAXN];

int main() {
	scanf("%d", &N);
	REP(i,N) REP(j,N) {
		int x;
		scanf("%d", &x);
		A[i][j] = x;
	}

	FOR(offset, -N, N) {
		int x = 0;
		int y = offset;
		ll total = 0;
		while (x < N && y < N) {
			if (y >= 0 && x < N && y < N) {
				total += A[y][x];
			}
			++x; ++y;
		}
		x = 0;
		y = offset;
		while (x < N && y < N) {
			if (y >= 0) {
				diag1[y][x] = total;
			}
			++x; ++y;
		}
	}

	FOR(offset, -N, N) {
		int x = N-1;
		int y = offset;
		ll total = 0;
		while (x >= 0 && y < N) {
			if (y >= 0) {
				total += A[y][x];
			}
			--x; ++y;
		}
		x = N-1;
		y = offset;
		while (x >= 0 && y < N) {
			if (y >= 0) {
				diag2[y][x] = total;
			}
			--x; ++y;
		}
	}

	int x1 = -1, y1 = -1, x2 = -1, y2 = -2;
	ll best1 = -1;
	ll best2 = -1;

	REP(y,N) REP(x,N) {
		ll opt = diag1[y][x] + diag2[y][x] - A[y][x];
		if ((x + y) % 2) {
			if (opt > best1) {
				best1 = opt;
				x1 = x; y1 = y;
			}
		} else {
			if (opt > best2) {
				best2 = opt;
				x2 = x; y2 = y;
			}
		}
	}

	printf("%I64d\n%d %d %d %d\n", best1+best2, y1+1, x1+1, y2+1, x2+1);

	return 0;
}