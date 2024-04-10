#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[300009];

bool ps(int l)
{
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] + l < m) {
			if (a[i] + l < r) return false;
			else r = max(r, a[i]);
		}
		else if ((a[i] + l) % m < r) r = max(r, a[i]);
	}
	return true;
}

int bs(int s, int e)
{
	int md = (s + e) / 2;
	if (s >= e) return md;
	if (ps(md)) return bs(s, md);
	return bs(md + 1, e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << bs(0, m - 1) << '\n';
	return 0;
}