#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 100005;
int n;
double p;
double a[N], b[N];

bool judge(double x) {
	double tot = p;
	for (int i = 0; i < n; i++) {
		tot += min(0.0, b[i] / x - a[i]);
		if (tot < 0) return false;
	}
	return true;
}

int main() {
	scanf("%d%lf", &n, &p);
	for (int i = 0; i < n; i++) scanf("%lf%lf", &a[i], &b[i]);
	double l = 0, r = 1e18;
	for (int i = 0; i < 100; i++) {
		double mid = (l + r) / 2;
		if (judge(mid)) l = mid;
		else r = mid;
	}
	if (l > 1e17) printf("-1\n");
	else printf("%.12f\n", l);
	return 0;
}