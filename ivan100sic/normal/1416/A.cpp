// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), sol(n+2, 123123123), vg(n+1);
		vector<basic_string<int>> e(n+1);
		for (int x=1; x<=n; x++) {
			e[x] = {-1};
		}

		for (int i=0; i<n; i++) {
			cin >> a[i];
			e[a[i]] += i;
		}

		for (int x=1; x<=n; x++) {
			e[x] += n;
			int g = 1;
			for (int j=0; j<(int)e[x].size()-1; j++) {
				g = max(g, e[x][j+1] - e[x][j]);
			}
			sol[g] = min(sol[g], x);
		}

		for (int i=1, z=123123123; i<=n; i++) {
			z = min(z, sol[i]);
			cout << (z == 123123123 ? -1 : z) << " \n"[i == n];
		}
	}
}