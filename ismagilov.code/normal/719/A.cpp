#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;

main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		if (a[0] == 15) {
			cout << "DOWN";
			return 0;
		}
		if (a[0] == 0) {
			cout << "UP";
			return 0;
		}
		cout << "-1";
		return 0;
	}
	if (a[n - 1] == 0) {
		cout << "UP";
		return 0;
	}
	if (a[n - 1] == 15) {
		cout << "DOWN";
		return 0;
	}
	if (a[n - 1] < a[n - 2]) {
		cout << "DOWN";
		return 0;
	}
	cout << "UP";
	return 0;
}