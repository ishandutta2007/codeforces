#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[105], b[105], n;

bool ok() {
	return accumulate(a, a+n, 0) % 2 == 0 &&
		accumulate(b, b+n, 0) % 2 == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i] >> b[i];

	if (ok()) {
		cout << "0\n";
		return 0;
	}

	for (int i=0; i<n; i++) {
		swap(a[i], b[i]);
		if (ok()) {
			cout << "1\n";
			return 0;
		}
		swap(a[i], b[i]);
	}

	cout << "-1\n";
}