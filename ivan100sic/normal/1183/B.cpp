#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	if (a.back() - a[0] <= 2*k) {
		cout << a[0] + k << '\n';
	} else {
		cout << "-1\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		solve();
}