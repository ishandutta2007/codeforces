#include <stdio.h>
#include <algorithm>
#include <queue>
#include <deque>
#include <memory.h>
#include <map>
#include <set>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

#define N 1555
char w[N][N];
int n, m;

struct point {
	long long x, y;
	int id;
} a[N];

int ke, fir[N], nxt[N + N], tov[N + N];
int h[N];
vector<int> sons[N];

void add(int x, int y) {
	nxt[++ke] = fir[x]; fir[x] = ke; tov[ke] = y;
	if (ke & 1) add(y, x);
}

void dfs(int x, int pr = -1) {
	h[x] = 1;
	for (int t = fir[x]; t; t = nxt[t])
		if (tov[t] != pr) {
			sons[x].push_back(tov[t]);
			dfs(tov[t], x);
			h[x] += h[tov[t]];
		}
}

vector<point> A[N];
int ki;

int quater(point A) {
	if (A.x < 0) {
		if (A.y < 0) return 3;
		return 4;
	}
	if (A.y < 0) return 2;
	return 1;
}

bool cmp(point A, point B) {
	return A.x * B.y - A.y * B.x < 0;
}

int ans[N];

void match(int x, point center, vector<point>& a) {
	ans[center.id] = x;

	for (int i = 0; i < a.size(); ++i) {
		a[i].x -= center.x;
		a[i].y -= center.y;
	}

	sort(a.begin(), a.end(), cmp);
	int lm = 0;
	for (int i = 0; i < sons[x].size(); ++i) {
		int y = sons[x][i];
		for (int j = 0; j + 1 < h[y]; ++j) {
			A[y].push_back(a[lm + j]);
		}
		match(y, a[lm + h[y] - 1], A[y]);
		lm += h[y];
	}
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	scanf("%d", &n);
	
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (n == 2) {
		cout << "1 2" << endl;
		return 0;
	}
	
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		add(x, y);
	}

	dfs(1);

	for (int i = 0; i < n; ++i) {
		point t;
		cin >> t.x >> t.y;
		t.id = i + 1;
		a[i] = t;
	}

	int cl = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i].x < a[cl].x || (a[i].x == a[cl].x && a[i].y < a[cl].y)) {
			cl = i;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (i != cl) {
			A[1].push_back(a[i]);
		}
	}

	match(1, a[cl], A[1]);

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
		 
	return 0;
}