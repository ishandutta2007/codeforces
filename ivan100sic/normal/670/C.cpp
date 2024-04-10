#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
map<int, int> a;
int b[200005], c[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}

	cin >> m;

	for (int i=1; i<=m; i++)
		cin >> b[i];
	for (int i=1; i<=m; i++)
		cin >> c[i];

	int u=-1, v=-1, sol=-1;
	for (int i=1; i<=m; i++) {
		int x = b[i], y = c[i];
		int p = a[x], q = a[y];
		if (tie(p, q) > tie(u, v)) {
			tie(u, v, sol) = tie(p, q, i);
		}
	}
	cout << sol << '\n';		

}