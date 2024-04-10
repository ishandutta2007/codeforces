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
		if (n > k) {
			if (n % k == 0) cout << 1 << '\n';
			else cout << 2 << '\n';
		}
		else if (n == k) cout << 1 << '\n';	
		else cout << (k - 1) / n + 1 << '\n';
	}
	return 0;
}