#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct drug {
	int x, y;
	bool operator< (const drug& b) const {
		return y < b.y;
	}

} a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, d;
	cin >> n >> d;
	for (int i=0; i<n; i++)
		cin >> a[i].y >> a[i].x;
	sort(a, a+n);
	int r = 0;
	ll w = 0, sol = 0;
	for (int l=0; l<n; l++) {
		while (r < n && a[r].y - a[l].y < d)
			w += a[r++].x;
		sol = max(sol, w);
		w -= a[l].x;
	}
	cout << sol << '\n';
}