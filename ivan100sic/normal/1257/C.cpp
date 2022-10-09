#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		map<int, int> seen;
		int sol = n+1;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (seen.count(a[i]))
				sol = min(sol, i - seen[a[i]] + 1);
			seen[a[i]] = i;
		}
		if (sol == n+1)
			sol = -1;
		cout << sol << '\n';
	}
}