#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		string s; cin >> s;
		int ans = n - 1;
		for (int i = 0; i < n; i++)
			if (s[i] == '>') {
				ans = min(ans, i);
				break;
			}
		for (int i = n - 1; i >= 0; i--)
			if (s[i] == '<') {
				ans = min(ans, n - 1 - i);
				break;
			}
		cout << ans << '\n';
	}
	return 0;
}