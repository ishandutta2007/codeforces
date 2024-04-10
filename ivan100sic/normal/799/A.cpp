#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, t, k, d;
	cin >> n >> t >> k >> d;

	int bez = (n + k - 1) / k * t;

	cerr << bez << '\n';

	int sal = d, sar = 2000000, sa = -1;
	while (sal <= sar) {
		int mid = (sal + sar) / 2;

		int cakes = mid / t * k + (mid - d) / t * k;

		if (cakes >= n) {
			sa = mid;
			sar = mid-1;
		} else {
			sal = mid+1;
		}
	}

	cerr << sa << '\n';

	cout << (sa < bez ? "YES" : "NO");
}