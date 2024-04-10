#include <bits/stdc++.h>
using namespace std;

int a[105], n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int x=0;
	for (int i=1; i<=n; i++) {
		if (a[i] > k)
			break;
		else
			x++;
	}

	int y=0;
	for (int i=n; i>=1; i--) {
		if (a[i] > k)
			break;
		else
			y++;
	}

	x += y;
	if (x == 2*n)
		x = n;

	cout << x << '\n';

}