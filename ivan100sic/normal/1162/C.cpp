#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int u[100005], v[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int x;
		cin >> x;
		if (!u[x])
			u[x] = i;
		v[x] = i;
	}

	int sol = 0;
	for (int i=1; i<=n; i++) {
		if (!u[i])
			sol++;
		if (i < n) {
			sol += 2;
			int p = u[i];
			int q = v[i+1];
			if (p && p < q) {
				sol--;
			}
			p = u[i+1];
			q = v[i];
			if (p && p < q) {
				sol--;
			}
		}
	}

	cout << sol << '\n';
}