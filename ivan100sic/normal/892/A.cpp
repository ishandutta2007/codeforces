#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005], b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}

	nth_element(b, b+n-2, b+n);
	bool ok = accumulate(a, a+n, 0ll) <= b[n-1] + b[n-2];
	cout << (ok ? "YES" : "NO");
}