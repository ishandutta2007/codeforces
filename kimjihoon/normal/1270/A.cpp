#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, n1, n2; cin >> n >> n1 >> n2;
		bool f = false;
		for (int i = 0; i < n1; i++) {
			int a; cin >> a;
			if (a == n) f = true;
		}
		for (int i = 0; i < n2; i++) {
			int a; cin >> a;
		}
		if (f) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}