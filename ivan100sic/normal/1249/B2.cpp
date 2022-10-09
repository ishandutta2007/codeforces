#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n), z(n), vis(n);
		for (int& x : p)
			cin >> x, x--;
		for (int i=0; i<n; i++) {
			if (!vis[i]) {
				int c = 0;
				for (int j=i; !vis[j]; j=p[j])
					vis[j] = 1, c++;
				for (int k=0, j=i; k<c; j=p[j], k++)
					z[j] = c;
			}
		}
		for (int x : z)
			cout << x << ' ';
		cout << '\n';
	}
}