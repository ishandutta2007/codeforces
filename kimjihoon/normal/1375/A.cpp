#include <iostream>
#include <algorithm>
using namespace std;

int a[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i % 2 == 1 && a[i] > 0) a[i] = -a[i];
			if (i % 2 == 0 && a[i] < 0) a[i] = -a[i];
		}
		for (int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << '\n';
	}
	return 0;
}