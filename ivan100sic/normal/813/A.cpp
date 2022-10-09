#include <bits/stdc++.h>
using namespace std;

int n, m;
bool moze[100005];
int a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i=1; i<=m; i++) {
		int l, r;
		cin >> l >> r;
		for (int j=l; j<=r; j++) {
			moze[j] = true;
		}
	}

	int sum = accumulate(a+1, a+n+1, 0);
	while (sum <= 100003) {
		if (!moze[sum]) {
			sum++;
		} else break;
	}
	if (sum > 100000) {
		sum = -1;
	}
	cout << sum;
}