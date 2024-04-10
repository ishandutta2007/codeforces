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
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 777777777;

int w[4][4];

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

struct my {
	int res[4][4];
	
	int sum() {
		int ans = 0;
		for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) add(ans, res[i][j]);
		return ans;
	}

	my() { 
		memset(res, 0, sizeof(res));
	}

	my(int x) { 
		memset(res, 0, sizeof(res));
		if (x) res[x][x] = 1;
		else for (int i = 1; i <= 3; i++) res[i][i] = 1;
	}
};

int n, m;
my t[2 * maxn];


my combine(my a, my b) {
	my res;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				for (int o = 1; o <= 3; o++) {
					add(res.res[i][o], (1LL * a.res[i][j] * b.res[k][o] % mod) * w[j][k]);
				}
			}
		}
	}
	return res;
}

void upd(int v, int tl, int tr, int x, int y) {
	if (tl == tr) {
		t[v] = my(y);
		return;
	}
	int tm = (tl + tr) >> 1;
	if (x <= tm) upd(v * 2, tl, tm, x, y);
	else upd(v * 2 + 1, tm + 1, tr, x, y);
	t[v] = combine(t[v * 2], t[v * 2 + 1]);
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = my(0);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = combine(t[v * 2], t[v * 2 + 1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) scanf("%d", &w[i][j]);
	build(1, 0, n - 1);
	//printf("%d\n", t[1].sum());
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		upd(1, 0, n - 1, x - 1, y);
		printf("%d\n", t[1].sum());
	}

	return 0;
}