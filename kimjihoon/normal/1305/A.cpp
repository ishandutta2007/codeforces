#include <iostream>
#include <algorithm>
using namespace std;

int a[109], b[109];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << '\n';
		for (int i = 0; i < n; i++)
			cout << b[i] << " ";
		cout << '\n';
	}
	return 0;
}