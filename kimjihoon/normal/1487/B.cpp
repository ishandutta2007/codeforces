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
		int r = ((k - 1) % n) + 1;
		if (n % 2 == 0) cout << r << '\n';
		else {
			int t = (k - 1) / ((n - 1) / 2);
			r = ((r - 1 + t) % n) + 1;
			cout << r << '\n';
		}
	}
	return 0;
}