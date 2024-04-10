#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		if (n == 1 && m == 1) cout << 0 << '\n';
		else cout << 2 * min(n, m) + max(n, m) - 2 << '\n';
	}
	return 0;
}