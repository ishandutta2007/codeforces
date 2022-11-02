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
		for (int i = 1; i <= 2 * n; i++)
			cin >> a[i];
		sort(a + 1, a + 2 * n + 1);
		for (int i = 1; i <= n; i++)
			cout << a[i] << " " << a[n + i] << " ";
		cout << '\n';
	}
	return 0;
}