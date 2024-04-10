// Hydro submission #61aad765ef9a89de1e7604b8@1638586213988
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve() {
	int n;
	long long c;
	cin >> n;
	cin >> c;
	vector<long long>a(n + 1);
	vector<long long>b(n);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n - 1; ++i)
		cin >> b[i];

	long long ans = 0x3f3f3f3f;
	long long  proDays = -1;
	long long left = 0;	
	for (int i = 1; i <= n; ++i) {
		++proDays;

		ans = min(ans, proDays + ((c - left) + a[i] - 1) / a[i]);

		if (i == n)
			break;

		proDays += ((b[i] - left) + a[i] - 1) / a[i];
		left = left + a[i] * (((b[i] - left) + a[i] - 1) / a[i]) - b[i];
	}

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
        return 0;
}