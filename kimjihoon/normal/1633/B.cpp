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
		int c0 = 0, c1 = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') c0++;
			else c1++;
		}
		if (c0 == c1) cout << c0 - 1 << '\n';
		else cout << min(c0, c1) << '\n';
	}
	return 0;
}