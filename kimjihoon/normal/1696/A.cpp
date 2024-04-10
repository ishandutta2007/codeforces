#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, x; cin >> n >> x;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			mx = max(mx, (x | a));
		}
		cout << mx << '\n';
	}
	return 0;
}