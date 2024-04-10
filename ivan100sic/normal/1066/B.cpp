#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, r;
int a[1005];

pair<int, int> b[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> r;
	int reach = 1, sol = 0;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	while (reach <= n) {
		bool ok = 0;
		for (int i=min(n, reach+r-1); i>=max(1, reach-r+1); i--) {
			if (a[i]) {
				reach = i+r;
				sol++;
				ok = 1;
				break;
			}
		}
		if (!ok) {
			cout << -1 << '\n';
			return 0;
		}
	}

	cout << sol << '\n';
}