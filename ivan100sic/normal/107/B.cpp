#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, h;
int a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> h;
	for (int i=1; i<=m; i++) {
		cin >> a[i];
	}
	int sum = accumulate(a+1, a+m+1, 0);
	if (sum < n) {
		cout << "-1\n";
		return 0;
	}
	a[h]--; n--; sum--;
	int g = a[h];

	// racunaj
	if (n > sum - g) {
		cout << "1\n";
		return 0;
	}

	double e = 1;
	for (int i=1; i<=g; i++) {
		e *= sum-g-n+i;
		e /= sum-g+i;
	}
	cout.precision(20);
	cout << fixed << 1 - e;


}