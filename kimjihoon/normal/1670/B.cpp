#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool f[256];
int a[100009], d[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
		for (int i = 'a'; i <= 'z'; i++)
			f[i] = false;
		for (int i = 0; i < k; i++) {
			char c; cin >> c;
			f[c] = true;
		}
		for (int i = 0; i < n; i++)
			a[i + 1] = f[s[i]];
		int c = n + 1, ans = 0;
		for (int i = n; i >= 1; i--) {
			c++;
			if (c <= n) ans = max(ans, c);
			if (a[i]) c = 0;
		}
		cout << ans << '\n';
	}
	return 0;
}