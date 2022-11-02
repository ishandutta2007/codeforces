#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		string s; cin >> s;
		int ans = 0;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == s[i - 1] || (i > 1 && s[i] == s[i - 2])) {
				s[i] = '.';
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}