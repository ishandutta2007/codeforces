#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, a[100009], b[100009];

bool ps(int l)
{
	int m = n + l, s = 100 * l;
	for (int i = 0; i < m - (m / 4) - l; i++)
		s += a[i];
	for (int i = 0; i < min(m - (m / 4), n); i++)
		s -= b[i];
	return (s >= 0);
}

int bs(int s, int e)
{
	int md = (s + e) / 2;
	while (s < e) {
		if (ps(md)) e = md;
		else s = md + 1;
		md = (s + e) / 2;
	}
	return md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		sort(a, a + n); sort(b, b + n);
		reverse(a, a + n); reverse(b, b + n);
		cout << bs(0, n * 3) << '\n';
	}
	return 0;
}