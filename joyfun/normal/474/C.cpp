#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int n;
double x[4], y[4], a[4], b[4];
double sx[4], sy[4];
int ans;

void rote(double &x, double &y, double a, double b) {
	x -= a; y -= b;
	double x1 = -y;
	double y1 = x;
	x = x1 + a;
	y = y1 + b;
}

double save[10];
int sn;

double dis(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

bool eq(double a, double b) {
	return fabs(a - b) < 1e-9;
}

bool judge() {
	sn = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			save[sn++] = dis(sx[i], sy[i], sx[j], sy[j]);
		}
	}
	sort(save, save + sn);
	if (fabs(save[0]) < 1e-9) return false;
	for (int i = 0; i < 3; i++)
		if (!eq(save[i], save[i + 1])) return false;
	if (!eq(save[4], save[5])) return false;
	if (!eq(save[3] * sqrt(2.0), save[4])) return false;
	return true;
}

void dfs(int u, int sum) {
	if (sum >= ans) return;
	if (u == 4) {
		if (judge())
			ans = min(ans, sum);
		return;
	}
	double xx = x[u], yy = y[u];
	for (int i = 0; i <= 3; i++) {
		sx[u] = xx; sy[u] = yy;
		dfs(u + 1, sum + i);
		rote(xx, yy, a[u], b[u]);
	}
}

int solve() {
	ans = INF;
	dfs(0, 0);
	if (ans == INF) ans = -1;
	return ans;
}

int main() {
	scanf("%d", &n);
	while (n--) {
		for (int i = 0; i < 4; i++)
			scanf("%lf%lf%lf%lf", &x[i], &y[i], &a[i], &b[i]);
		printf("%d\n", solve());
	}
	return 0;
}