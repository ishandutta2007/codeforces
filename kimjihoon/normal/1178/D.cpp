#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int c = 0;
	for (int i = n; i <= n + n / 2; i++) {
		bool pf = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				pf = false;
				break;
			}
		}
		if (pf) {
			c = i;
			break;
		}
	}
	cout << c << '\n';
	for (int i = 1; i <= n; i++)
		cout << i << " " << (i % n) + 1 << '\n';
	for (int i = 1; i <= c - n; i++)
		cout << i << " " << i + n / 2 << '\n';
	return 0;
}