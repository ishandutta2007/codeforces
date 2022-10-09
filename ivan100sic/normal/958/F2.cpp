// this is my code from vjudge
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[200005], r[200005], c[200005], poz;

void izbaci(int x) {
	c[x]++;
	if (c[x] == 1)
		poz++;
}

void ubaci(int x) {
	c[x]--;
	if (c[x] == 0)
		poz--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	int zbir = 0;
	for (int i=1; i<=m; i++) {
		cin >> c[i];
		zbir += c[i];
		if (c[i] > 0)
			poz++;
	}
	int sol = 123123123;
	for (int i=1; i<=n; i++) {
		r[i] = r[i-1];
		if (i > 1)
			izbaci(a[i-1]);
		while (r[i] < n && poz > 0) {
			r[i]++;
			ubaci(a[r[i]]);
		}
		if (poz == 0) {
			sol = min(sol, r[i] - i + 1);
		}
	}
	if (sol == 123123123) {
		cout << "-1\n";
	} else {
		cout << sol - zbir << '\n';
	}
}