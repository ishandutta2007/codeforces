#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#define y0 lal
#define y1 shatal

#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};


int n, b, q;
int x0[maxn], y0[maxn], x1[maxn], y1[maxn];
int x[maxn], y[maxn];
ll t[maxn];
char d[maxn];

void reading() {
	scanf("%d%d", &n, &b);
	for (int i = 0; i < n; i++) scanf("%d%d%d%d", &x0[i], &y0[i], &x1[i], &y1[i]);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) scanf("%d%d %c%I64d", &x[i], &y[i], &d[i], &t[i]);
}

int oo1(char c) {
	if (c == 'D') return 3;
	if (c == 'U') return 2;
	if (c == 'R') return 0;
	if (c == 'L') return 1;
	assert(0);
}

int oo2(int i) {
	if (x1[i] > x0[i]) return 0;
	if (x1[i] < x0[i]) return 1;
	if (y1[i] > y0[i]) return 2;
	if (y1[i] < y0[i]) return 3;
	assert(0);
}

int a[32][32];
int was[32][32][4];

bool ok(int x, int y) {
	return 0 <= x && x <= b && 0 <= y && y <= b;
}

void slowsolve() {
	memset(a, -1, sizeof(a));
	for (int i = 0; i < q; i++) d[i] = oo1(d[i]);
	for (int i = 0; i < n; i++) {
		int k = oo2(i);
		int X = x0[i], Y = y0[i];
		a[Y][X] = k;
		do {
			X += dx[k];
			Y += dy[k];
			a[Y][X] = k;
		} while (X != x1[i] || Y != y1[i]);
	}

	for (int i = 0; i < q; i++) {
		memset(was, -1, sizeof(was));
		int timer = 0;
		int curx = x[i], cury = y[i], curd = d[i];
		while (ok(curx, cury) && was[cury][curx][curd] == -1 && t[i] > 0) {
			was[cury][curx][curd] = timer++;
			if (a[cury][curx] != -1) curd = a[cury][curx];
			curx += dx[curd];
			cury += dy[curd];
			t[i]--;
		}
		if (!ok(curx, cury)) {
			curx -= dx[curd];
			cury -= dy[curd];
			printf("%d %d\n", curx, cury);
			continue;
		}
		if (t[i] > 0) t[i] %= (timer - was[cury][curx][curd]);
		for (int o = 0; o < t[i]; o++) {
			if (a[cury][curx] != -1) curd = a[cury][curx];
			curx += dx[curd];
			cury += dy[curd];		
		}
		printf("%d %d\n", curx, cury);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	reading();
	slowsolve();

	return 0;
}