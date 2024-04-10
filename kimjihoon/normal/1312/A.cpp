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
		if (n % m == 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}