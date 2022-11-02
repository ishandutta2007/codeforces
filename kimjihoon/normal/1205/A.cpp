#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	if (n % 2 == 0) cout << "NO" << '\n';
	else {
		cout << "YES" << '\n';
		int c = 1;
		for (int i = 1; i <= n; i++) {
			cout << c << " ";
			c += 1 + (i % 2) * 2;
		}
		c = 2;
		for (int i = 0; i < n; i++) {
			cout << c << " ";
			c += 1 + (i % 2) * 2;
		}
		cout << '\n';
	}
	return 0;
}