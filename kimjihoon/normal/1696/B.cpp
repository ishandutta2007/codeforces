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
		int ans = 0, pr = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			if (!pr && a) ans++;
			pr = a;
		}
		cout << min(ans, 2) << '\n';
	}
	return 0;
}