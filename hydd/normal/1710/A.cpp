#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n, m, k, a[110000];
ll sum;

bool check(int n, int m) {
	if (sum < 1ll * n * m)
		return false;
	bool ok = false;
	int res = n;
	for (int i = 1; i <= k; i++)
		if (a[i] / m > 1) {
			if (a[i] / m > 2)
				ok = true;
			if (res > 1)
				res -= a[i] / m;
			else if (res == 1) {
				if (!ok)
					return false;
				res -= a[i] / m;
			}
		}
	return (res <= 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		sum = 0;
		for (int i = 1; i <= k; i++)
			cin >> a[i], sum += a[i];
		sort(a + 1, a + k + 1, greater<int>());
		puts(check(n, m) || check(m, n) ? "Yes" : "No");
	}
	return 0;
}