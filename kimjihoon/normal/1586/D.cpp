#include <iostream>
#include <algorithm>
using namespace std;

int r[109], ans[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int sp = 0;
	for (int i = 1; i <= n; i++) {
		cout << "? ";
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << 2 << " ";
			else
				cout << 1 << " ";
		}
		cout << endl;
		int k; cin >> k;
		if (k && k != i)
			r[i] = k;

		cout << "? ";
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << 1 << " ";
			else
				cout << 2 << " ";
		}
		cout << endl;
		cin >> k;
		if (!k)
			sp = i;
		else if (k != i)
			r[k] = i;
	}
	for (int i = 1; i <= n; i++) {
		ans[sp] = i;
		sp = r[sp];
	}
	cout << "! ";
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}