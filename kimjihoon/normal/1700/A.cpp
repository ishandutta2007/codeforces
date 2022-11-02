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
		cout << 1LL * m * (m - 1) / 2LL + 1LL * n * (n + 1) / 2LL * m << '\n';
	}
	return 0;
}