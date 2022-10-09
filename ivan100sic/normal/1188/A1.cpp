#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int e[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u]++;
		e[v]++;
	}

	for (int i=1; i<=n; i++)
		if (e[i] == 2) {
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
}