#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool p[29], r[29][29];
vector<int> v[29];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		string a, b; cin >> a >> b;
		bool f = false;
		for (int i = 0; i < 26; i++) {
			p[i] = 0;
			for (int j = 0; j < 26; j++)
				r[i][j] = 0;
			r[i][i] = true;
		}
		for (int i = 0; i < n; i++) {
			if (a[i] > b[i]) {
				f = true;
				break;
			}
			r[a[i] - 'a'][b[i] - 'a'] = true;
		}
		if (f) {
			cout << -1 << '\n';
			continue;
		}
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			int tp = -1;
			for (int j = i + 1; j < 26; j++) {
				if (r[i][j] && tp == -1) {
					tp = j;
					ans++;
				}
				if (r[i][j] && tp != -1)
					r[tp][j] = 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}