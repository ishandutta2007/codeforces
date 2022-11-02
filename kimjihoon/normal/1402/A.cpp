#include <iostream>
#include <algorithm>
using namespace std;

int a[100009], p[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (n > 1) p[i] = n - 1 - (((a[i] % (n - 1)) + n - 1) % (n - 1));
	}
	if (n == 1) {
		cout << 1 << " " << 1 << '\n';
		cout << -a[1] << '\n';
		cout << 1 << " " << 1 << '\n';
		cout << 1 << '\n';
		cout << 1 << " " << 1 << '\n';
		cout << -1 << '\n';
		return 0;
	}
	cout << 1 << " " << n << '\n';
	for (int i = 1; i <= n; i++)
		cout << 1LL * p[i] * n << " ";
	cout << '\n';
	cout << 1 << " " << 1 << '\n';
	cout << -1LL * a[1] + -1LL * p[1] * n << '\n';
	cout << 2 << " " << n << '\n';
	for (int i = 2; i <= n; i++)
		cout << -1LL * a[i] + -1LL * p[i] * n << " ";
	cout << '\n';
	return 0;
}