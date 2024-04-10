#include <iostream>
using namespace std;

int p[400009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < n; i++) cin >> p[i];
		int tc = 0;
		for (int i = 0; i < n / 2; i++) {
			tc++;
			if (i == n - 1 || p[i] != p[i + 1]) {
				if (!a) a += tc;
				else if (b <= a) b += tc;
				else c += tc;
				tc = 0;
			}
		}
		if (a == 0 || b <= a || c <= a) cout << 0 << " " << 0 << " " << 0 << '\n';
		else cout << a << " " << b << " " << c << '\n';
	}
	return 0;
}