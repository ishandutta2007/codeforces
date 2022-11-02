#include <iostream>
#include <algorithm>
using namespace std;

bool vs[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			vs[i] = false;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			a = (a + i) % n;
			if (a < 0) a += n;
			vs[a] = true;
		}
		bool f = true;
		for (int i = 0; i < n; i++)
			if (!vs[i]) {
				f = false;
				break;
			}
		if (f) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}