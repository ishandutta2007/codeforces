#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long i64;

i64 n, m, k, x, s;
i64 a[200005], b[200005], c[200005], d[200005];

pair<i64, i64> e[200005];

int main() {
	cin >> n >> m >> k >> x >> s;

	for (int i=0; i<m; i++) {
		cin >> e[i].second;
	}
	for (int i=0; i<m; i++) {
		cin >> e[i].first;
	}
	sort(e, e+m);

	for (int i=0; i<m; i++) {
		a[i] = e[i].second;
		b[i] = e[i].first;
		if (i > 0 && a[i-1] < a[i]) {
			a[i] = a[i-1];
		}
	}

	for (int i=1; i<=k; i++) {
		cin >> c[i];
	}
	for (int i=1; i<=k; i++) {
		cin >> d[i];
	}

	k++;

	int good = m-1;
	i64 sol = n * x;

	for (int i=0; i<k; i++) {
		i64 rest = s - d[i];
		if (rest < 0) break;
		while (good >= 0 && b[good] > rest) {
			good--;
		}

		i64 timme = (n - c[i]) * x;
		sol = min(sol, timme);

		if (good >= 0) {
			timme = (n - c[i]) * a[good];
			sol = min(sol, timme);
		}
	}

	cout << sol;
}