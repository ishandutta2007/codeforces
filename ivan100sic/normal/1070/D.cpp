#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	ll pre = 0, sol = 0;
	cin >> n >> k;
	while (n--) {
		int x;
		cin >> x;

		if (pre == 0) {
			sol += x / k;
			pre = x % k;
		} else {
			if (pre + x >= k) {
				sol += (pre + x) / k;
				pre = (pre + x) % k;
			} else {
				sol++;
				pre = 0;
			}
		}
	}

	if (pre)
		sol++;

	cout << sol << '\n';
}