#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, u;
int a[100005];
double sol = -5;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> u;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++) {
		int j = upper_bound(a, a+n, a[i] + u) - 1 - a;
		if (i == j || i == j - 1)
			continue;
		int k = i+1;
		sol = max(sol, 1.0 * (a[j] - a[k]) / (a[j] - a[i]));
	}

	cout.precision(20);
	cout << fixed;

	if (sol < 0)
		cout << "-1\n";
	else
		cout << sol << '\n';
}