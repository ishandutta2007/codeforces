#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, h;
int a[300005], ainv[300005];
basic_string<pair<int, int>> sol;

void dod(int l, int r) {
	sol += {l, r};
	swap(a[l], a[r]);
	ainv[a[l]] = l;
	ainv[a[r]] = r;
}

/*


O----1---0----I
first-last
I----1---0----O
onda cik cak

*/

/*
3 4 1 2
2 4 1 3
3 4 1 2
1 4 3 2
1 2 3 4

*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	h = n >> 1;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		ainv[a[i]] = i;
	}

	int l = 1, r = n;
	while (1) {
		while (l <= n && a[l] <= h)
			l++;
		while (r >= 1 && a[r] > h)
			r--;
		if (l > r)
			break;

		if (r-l >= h) {
			dod(l, r);
		} else {
			dod(1, n);
			dod(1, r);
			dod(l, n);
		}
	}

	for (int i=1; i<=h; i++) {
		int j = ainv[i];
		if (i != j) {
			dod(i, n);
			dod(j, n);
			dod(i, n);
		}
	}

	for (int i=h+1; i<=n; i++) {
		int j = ainv[i];
		if (i != j) {
			dod(i, 1);
			dod(j, 1);
			dod(i, 1);
		}
	}

	cerr << is_sorted(a+1, a+n+1) << '\n';

	cout << sol.size() << '\n';
	for (auto [x, y] : sol)
		cout << x << ' ' << y << '\n';
}