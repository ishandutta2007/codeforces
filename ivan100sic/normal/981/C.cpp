#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int deg[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	if (n == 2) {
		cout << "Yes\n1\n1 2\n";
		return 0;
	}

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}

	int r = max_element(deg+1, deg+n+1) - deg;

	if (count_if(deg+1, deg+n+1, [](int x) { return x > 2;}) > 1) {
		cout << "No\n";
		return 0;
	}

	cout << "Yes\n";
	cout << count(deg+1, deg+n+1, 1) << '\n';
	for (int i=1; i<=n; i++) {
		if (deg[i] == 1) {
			cout << r << ' ' << i << '\n';
		}
	}

}