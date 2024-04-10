#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, k; cin >> n >> k;
		int l = k - 1;
		l = l / 2 + 1;
		cout << n - l << '\n';
		for (int i = l; i <= n; i++)
			if (i != k)
				cout << i << " ";
		cout << '\n';
	}
	return 0;
}