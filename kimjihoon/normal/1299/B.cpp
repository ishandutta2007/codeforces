#include <iostream>
using namespace std;

int x[100009], y[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	if (n % 2 != 0) {
		cout << "NO" << '\n';
		return 0;
	}
	int mx = 0, my = 0;
	for (int i = 0; i < n / 2; i++) {
		int tx = x[i] + x[i + n / 2], ty = y[i] + y[i + n / 2];
		if (i == 0) { mx = tx; my = ty; }
		else if (mx != tx || my != ty) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
	return 0;
}