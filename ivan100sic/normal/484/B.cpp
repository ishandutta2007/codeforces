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

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	n = unique(a, a+n) - a;
	int sol = 0;
	for (int i=n-1; i>=0; i--) {
		if (a[i] <= sol)
			break;
		for (int j=2*a[i]; j<=1000000+a[i]; j+=a[i]) {
			auto it = lower_bound(a+i+1, a+n, j);
			--it;
			sol = max(sol, *it % a[i]);
		}
	}
	cout << sol << '\n';
}