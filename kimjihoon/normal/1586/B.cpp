#include <iostream>
#include <algorithm>
using namespace std;

bool vs[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++)
			vs[i] = false;
		for (int i = 1; i <= m; i++) {
			int a, b, c; cin >> a >> b >> c;
			vs[b] = true;
		}
		int t = 0;
		for (int i = 1; i <= n; i++) {
			if (!vs[i]) {
				t = i;
				break;
			}
		}
		for (int i = 1; i <= n; i++)
			if (i != t)
				cout << t << " " << i << '\n';
	}
	return 0;
}