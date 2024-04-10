#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m; j++) {
			cout << i + 1 << " " << j + 1 << '\n';
			cout << n - i << " " << m - j << '\n';
		}
	}
	if (n % 2) {
		for (int i = 0; i < m / 2; i++) {
			cout << n / 2 + 1 << " " << i + 1 << '\n';
			cout << n / 2 + 1 << " " << m - i << '\n';
		}
		if (m % 2) cout << n / 2 + 1 << " " << m / 2 + 1 << '\n';
	}
	return 0;
}