#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> a[i];
		sort(a, a+n, greater<int>());
		int sol = 0;
		for (int i=0; i<n; i++)
			sol = max(sol, min(i+1, a[i]));
		cout << sol << '\n';
	}
}