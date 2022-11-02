#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int a, b, n; cin >> a >> b >> n;
		if (n % 3 == 0) cout << a << '\n';
		else if (n % 3 == 1) cout << b << '\n';
		else cout << (a ^ b) << '\n';
	}
	return 0;
}