#include <iostream>
using namespace std;

bool vs[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int ans = -1, c = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (ans != -1) continue;
		if (a > n || a > c) {
			ans = i + 1;
			continue;
		}
		vs[a] = true;
		while (vs[c])
			c++;
	}
	cout << ans << '\n';
	return 0;
}