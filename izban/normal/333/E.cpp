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

const int maxn = 3072;
const int inf = 1000000007;
const int mod = 1000000007;

double sqr(double x) {
	return x * x;
}

struct pt {
	int x, y;

	void read() {
		cin >> x >> y;
	}

	pt () {}
	pt (int nx, int ny) : x(nx), y(ny) {}	
	
	double d() const {
		return sqrt(sqr(x) + sqr(y));
	}

	pt operator- (const pt &p) const {
		return pt(x - p.x, y - p.y);
	}

	int operator^ (const pt &p) const {
		return x * p.y - y * p.x;
	}

	bool operator< (const pt &p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
};

int n;
vector<pt> a;
double ds[maxn][maxn];
int v[maxn], up[maxn], down[maxn], g[maxn];
int szv, szup, szdown, szg;

void convex_hull(int o, double x) {
	pt p = a[o];
	szv = szup = szdown = szg = 0;

	for (int i = 0; i < a.size(); i++) {
		if (ds[i][o] > (2 * x)) 
			v[szv++] = i;
	}
	if (szv <= 2) {
		for (int i = 0; i < szv; i++) g[i] = v[i];
		szg = szv;
		return;
	}
	pt last = a[v[szv - 1]];
	pt first = a[v[0]];

	for (int i = 0; i < szv; i++) {
		if (!i || ((a[v[i]] - a[up[szup - 1]]) ^ (last - first)) < 0 || i == szv - 1) {
			while (szup >= 2 && ((a[v[i]] - a[up[szup - 1]]) ^ (a[up[szup - 1]] - a[up[szup - 2]])) <= 0)
				szup--;
			up[szup++] = v[i];
		}
		if (!i || ((a[v[i]] - a[down[szdown - 1]]) ^ (last - first)) > 0 || i == szv - 1) {
			while (szdown >= 2 && ((a[v[i]] - a[down[szdown - 1]]) ^ (a[down[szdown - 1]] - a[down[szdown - 2]])) >= 0) 
				szdown--;
			down[szdown++] = v[i];
		}
	}
	for (int i = 0; i < szdown; i++) g[szg++] = down[i];
	for (int i = szup - 2; i > 0; i--) g[szg++] = up[i];;
	szg = szg;
	szg = szg;
}

int dist(pt p, int A, int B, int C) {
	return abs(A * p.x + B * p.y + C);
}

bool f(double x) {
	double mx = 0;
	for (int i = 0; i < n; i++) {
		convex_hull(i, x);
		int cur = szg ? 1 % szg : 0;
		for (int j = 0; j < szg; j++) {
			int nj = (j + 1) % szg;
			int A = a[g[j]].y - a[g[nj]].y;
			int B = a[g[nj]].x - a[g[j]].x;
			int C = - (A * a[g[j]].x + B * a[g[j]].y);
			
			while (dist(a[g[(cur + 1) % szg]], A, B, C) > dist(a[g[cur]], A, B, C)) cur = (cur + 1) % szg;
			mx = max(mx, ds[g[cur]][g[j]]);
			mx = max(mx, ds[g[cur]][g[nj]]);
		}
	}
	return mx > (2 * x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		a.resize(n);
		for (int i = 0; i < n; i++) a[i].read();
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ds[i][j] = (a[i] - a[j]).d();

		double l = 0, r = 1.6e4;
		for (int it = 0; it < 34; it++) {
			double m = (l + r) / 2.0;
			if (f(m)) l = m;
			else r = m;
		}
		printf("%.10lf\n", (l + r) / 2.0);
	}
	
	return 0;
}