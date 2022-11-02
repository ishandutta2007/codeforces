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
		int n; cin >> n;
		string s; cin >> s;
		int c0 = 0, c1 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0')
				c0++;
			else
				c1++;
		}
		if (c0 > 1 || c1 > 1) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
	return 0;
}