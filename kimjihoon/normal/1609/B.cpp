#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q; cin >> n >> q;
	string s; cin >> s;
	int ans = 0;
	for (int i = 0; i < n - 2; i++)
		if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
			ans++;
	for (int i = 0; i < q; i++) {
		int p; char c; cin >> p >> c;
		p--;
		if (s[p] != c) {
			for (int j = max(0, p - 2); j <= p; j++)
				if (j + 2 < n && s[j] == 'a' && s[j + 1] == 'b' && s[j + 2] == 'c')
					ans--;
			s[p] = c;
			for (int j = max(0, p - 2); j <= p; j++)
				if (j + 2 < n && s[j] == 'a' && s[j + 1] == 'b' && s[j + 2] == 'c')
					ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}