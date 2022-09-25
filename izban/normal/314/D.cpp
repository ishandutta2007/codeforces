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


using namespace std;

#define ll long long
#define y0 nenavizhu
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int x0[maxn], y0[maxn];
vector<int> x, y;


bool cmp1(int i, int j) {
	return x[i] < x[j] || x[i] == x[j] && y[i] < y[j];
}

bool f(ll d) {
	vector<int> p;
	for (int i = 0; i < n; i++) p.push_back(i);
	sort(p.begin(), p.end(), cmp1);

	vector<int> Lmx(n), Lmn(n), Rmx(n), Rmn(n);
	Lmx[0] = Lmn[0] = y[p[0]], Rmx[n - 1] = Rmn[n - 1] = y[p[n - 1]];
	for (int i = 1; i < n; i++) {
		Lmx[i] = max(Lmx[i - 1], y[p[i]]);
		Lmn[i] = min(Lmn[i - 1], y[p[i]]);
	}
	for (int i = n - 2; i >= 0; i--) {
		Rmx[i] = max(Rmx[i + 1], y[p[i]]);
		Rmn[i] = min(Rmn[i + 1], y[p[i]]);
	}

	int r = -1;
	for (int l = 0; l < n; l++) {
		while (r < n - 1 && x[p[r + 1]] - x[p[l]] <= d) ++r;
		int mxY = -2e9, mnY = 2e9;
		if (r < n - 1) mxY = max(mxY, Rmx[r + 1]), mnY = min(mnY, Rmn[r + 1]);
		if (l) mxY = max(mxY, Lmx[l - 1]), mnY = min(mnY, Lmn[l - 1]);
		if ((ll)mxY - (ll)mnY <= d) return 1;
	}
	return 0;
}

ll fastsolve() {
	x.assign(n, 0);
	y.assign(n, 0);
	for (int i = 0; i < n; i++) {
		x[i] = 1 * (x0[i] + y0[i]);
		y[i] = 1 * (x0[i] - y0[i]);
	}
	
	ll L = 0, R = 4e9;
	while (R - L > 1) {
		ll m = (L + R) >> 1;
		if (f(m)) R = m;
		else L = m;
	}

	if (f(L)) return L;
	else return R;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d%d", &x0[i], &y0[i]);
	
	printf("%.1lf", fastsolve() / 2.0);

	return 0;
}