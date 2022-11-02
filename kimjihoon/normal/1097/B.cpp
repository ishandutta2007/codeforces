#include <iostream>
using namespace std;

int a[19];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < (1 << n); i++) {
		int s = 0;
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) != 0)
				s += a[j];
			else
				s -= a[j];
		}
		if (s % 360 == 0) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
	return 0;
}