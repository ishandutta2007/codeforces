#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		string a, b; cin >> a >> b;
		if (n == m) {
			if (a == b) cout << "YES" << '\n';
			else cout << "NO" << '\n';
			continue;
		}
		bool f = true, tf = false;
		for (int i = 1; i < m; i++)
			if (a[n - i] != b[m - i]) {
				f = false;
				break;
			}
		for (int i = 0; i < n - m + 1; i++)
			if (a[i] == b[0]) {
				tf = true;
				break;
			}
		if (f && tf) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}