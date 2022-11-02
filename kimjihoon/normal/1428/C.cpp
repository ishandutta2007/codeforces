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
		int ans = s.length();
		int pi = 1;
		for (int i = 1; i < s.length(); i++) {
			if (pi > 0 && s[i] == 'B') {
				ans -= 2;
				pi -= 2;
			}
			pi++;
		}
		cout << ans << '\n';
	}
	return 0;
}