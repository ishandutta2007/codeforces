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
	if (n == 0) {
		cout << 1;
		return 0;
	}
	if (n % 4 == 0) {
		cout << 6;
		return 0;
	}
	if (n % 4 == 1) {
		cout << 8;
		return 0;
	}
	if (n % 4 == 2) {
		cout << 4;
		return 0;
	}
	if (n % 4 == 3) {
		cout << 2;
		return 0;
	}
}