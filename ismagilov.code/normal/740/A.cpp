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
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int k = 4 - (n % 4);
	if (k == 4) {
		cout << 0;
	}
	else {
		if (k == 1) {
			cout << min(a, min(b + c, 3 * c));
		}
		if (k == 2) {
			cout << min(b, min(a * 2, c * 2));
		}
		if (k == 3) {
			cout << min(c, min(3 * a, b + a));
		}
	}
}