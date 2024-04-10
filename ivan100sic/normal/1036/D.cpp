#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, x, y, len;
ll a[300005], b[300005];
ll sx, sy;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> m;
	for (int i=0; i<m; i++)
		cin >> b[i];

	if (accumulate(a, a+n, 0ll) != accumulate(b, b+m, 0ll))
		return cout << "-1\n", 0;

	while (x < n || y < m) {
		if (sx == sy) {
			// cerr << "match: " << x << ' ' << y << '\n';
			len++;
			sx += a[x++];
			sy += b[y++];
		} else if (sx < sy) {
			sx += a[x++];
		} else {
			sy += b[y++];
		}
	}

	cout << len << '\n';

}