#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		string s; cin >> s;
		int ans = 0;
		for (int i = 0; i < s.length(); i++)
			ans = max(ans, (int)(s[i] - '0'));
		cout << ans << '\n';
	}
	return 0;
}