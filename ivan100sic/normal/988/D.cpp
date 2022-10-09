#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
set<long long> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	sort(a, a+n);

	// 3?
	for (int i=0; i<n; i++) {
		for (long long j=1; j<=2e9; j*=2) {
			if (a[i] - j < a[0])
				break;
			if (a[i] + j > a[n-1])
				break;

			if (s.count(a[i] - j) && s.count(a[i] + j))
				return cout << "3\n" << a[i] << ' ' << a[i] - j << ' ' << a[i] + j << '\n', 0;
		}
	}

	// 2?
	for (int i=0; i<n; i++) {
		for (long long j=1; j<=2e9; j*=2) {
			if (a[i] - j < a[0])
				break;

			if (s.count(a[i] - j))
				return cout << "2\n" << a[i] << ' ' << a[i] - j << '\n', 0;
		}
	}

	cout << "1\n" << a[0] << '\n';



}