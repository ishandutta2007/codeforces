#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define rep(i, n) for (int i = 0; i < n; ++ i)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int inf = 0x3f3f3f3f;
const ll linf = 1LL << 60;
const ld eps = 1e-9;
int read() {
	int x = 0, f = 1, c = getchar();
	for(;!isdigit(c); c = getchar()) if(c == '-') f ^= 1;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}
void write(int x) {
	if (!x) {putchar('0'); return;}
	if (x < 0) putchar('-'), x = -x;
	int stk[10], tp = 0;
	for (; x; x /= 10) stk[tp ++] = x - x / 10 * 10;
	for (; tp; putchar(48 + stk[-- tp]));
}

const int N = 33;
const int B = 333;

const char * DIR = "UDLR";
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int getDir(char c) {
	return strchr(DIR, c) - DIR;
}

struct P {
	int x, y;
	P() {}
	P(int a, int b): x(a), y(b) {}
};

struct ST {
	P p;
	int dir;
	ST() {}
	ST(P a, int b):  p(a), dir(b) {}
};

int n, b, q;
vector <pair <P, P> > arrow;
ST go[N][N][4][50];
int godir[N][N];

void precalc() {
	memset(godir, -1, sizeof godir);
	for (int i = 0; i < n; ++ i) {
		P x = arrow[i].F, y = arrow[i].S;
		if (x.x == y.x) {
			if (x.y < y.y)
				for (int j = x.y; j <= y.y; ++ j) godir[x.x][j] = 0;
			else
				for (int j = y.y; j <= x.y; ++ j) godir[x.x][j] = 1;
		} else {
			if (x.x < y.x)
				for (int j = x.x; j <= y.x; ++ j) godir[j][x.y] = 3;
			else
				for (int j = y.x; j <= x.x; ++ j) godir[j][x.y] = 2;
		}
	}
	for (int stp = 0; stp < 50; ++ stp) {
		for (int i = 0; i <= b; ++ i) {
			for (int j = 0; j <= b; ++ j) {
				for (int dir = 0; dir < 4; ++ dir) {
					if (!stp) {
						int ndir = godir[i][j];
						if (!~ndir) ndir = dir;
						int ni = i + dx[ndir];
						int nj = j + dy[ndir];
						go[i][j][dir][0] = ST(P(ni, nj), ndir);
					} else {
						ST a = go[i][j][dir][stp - 1];
						int x = a.p.x, y = a.p.y, ndir = a.dir;
						if (x < 0 || y < 0 || x > b || y > b) go[i][j][dir][stp] = a;
						else go[i][j][dir][stp] = go[x][y][ndir][stp - 1];
					}
				}
			}
		}
	}
}

int main() {
	n = read(), b = read();
	for (int i = 0; i < n; ++ i) {
		P x, y;
		x.x = read(), x.y = read();
		y.x = read(), y.y = read();
		arrow.PB(MP(x, y));
	}
	precalc();
	q = read();
	for (int i = 0; i < q; ++ i) {
		int x = read(), y = read();
		char c = getchar();
		int dir = getDir(c);
		ll t; scanf("%lld", &t);
		for (int j = 0; j <= 50; ++ j) {
			if (t & 1LL << j) {
				ST a = go[x][y][dir][j];
				x = a.p.x, y = a.p.y, dir = a.dir;
				if (x < 0 || y < 0 || x > b || y > b) break;
			}
		}
		if (x < 0 || y < 0 || x > b || y > b)
			x -= dx[dir], y -= dy[dir];
		write(x); putchar(' '); write(y); putchar('\n');
	}
	return 0;
}