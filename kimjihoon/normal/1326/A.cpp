#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		if (n == 1) {
			cout << -1 << '\n';
			continue;
		}
		cout << 2;
		for (int i = 0; i < n - 1; i++)
			cout << 3;
		cout << '\n';
	}
	return 0;
}