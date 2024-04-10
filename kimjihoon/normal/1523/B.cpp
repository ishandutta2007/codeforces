#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[10009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		cout << n * 3 << '\n';
		for (int i = 1; i <= n; i += 2) {
			int a = i, b = i + 1;
			cout << 1 << " " << a << " " << b << '\n';
			cout << 2 << " " << a << " " << b << '\n';
			cout << 1 << " " << a << " " << b << '\n';
			cout << 2 << " " << a << " " << b << '\n';
			cout << 1 << " " << a << " " << b << '\n';
			cout << 2 << " " << a << " " << b << '\n';
		}
	}
	return 0;
}