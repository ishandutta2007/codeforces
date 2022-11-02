#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int p = 0, s = 0;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			s += a;
			if (a & 1) p = i;
		}
		bool f = false;
		for (int i = 2; i * i <= s; i++)
			if (s % i == 0) {
				f = true;
				break;
			}
		if (f) {
			cout << n << '\n';
			for (int i = 1; i <= n; i++)
				cout << i << " ";
			cout << '\n';
			continue;
		}
		cout << n - 1 << '\n';
		for (int i = 1; i <= n; i++)
			if (i != p)
				cout << i << " ";
		cout << '\n';
	}
	return 0;
}