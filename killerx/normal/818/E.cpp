#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

const int N = 1 << 17;

int n, K;
int a[N];
int b[N][35];

vector <pair <int, int> > fac(int x) {
	vector <pair <int, int> > pw;
	for (int i = 2; 1LL * i * i <= x; ++ i) {
		if (x % i == 0) {
			pw.pb(mp(i, 0));
			while (x % i == 0) {
				pw[pw.size() - 1].second ++;
				x /= i;
			}
		}
	}
	if (x > 1) pw.pb(mp(x, 1));
	return pw;
}

vector <pair <int, int> > need;
int nw[35];

bool check() {
	for (int i = 0; i < need.size(); ++ i) {
		if (nw[i] < need[i].second) return 0;
	}
	return 1;
}

int main() {
	scanf("%d %d", &n, &K);
	need = fac(K);
	int m = need.size();
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
		for (int j = 0; j < m; ++ j) {
			while (a[i] % need[j].first == 0) {
				b[i][j] ++;
				a[i] /= need[j].first;
			}
		}
	}
	ll ans = 0;
	for (int x = 0, y = -1; x < n; ++ x) {
		while (y < n && !check()) {
			++ y;
			for (int i = 0; i < m; ++ i) nw[i] += b[y][i];
		}
		ans += n - max(x, y);
		for (int i = 0; i < m; ++ i) nw[i] -= b[x][i];
	}
	printf("%lld\n", ans);
	return 0;
}