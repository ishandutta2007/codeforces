#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int c[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		string s, t; cin >> s >> t;
		int n = s.length();
		for (int i = 0; i < 26; i++)
			c[i] = 0;
		for (int i = 0; i < n; i++)
			c[(int)(s[i] - 'a')]++;
		for (int i = 0; i < 26; i++) {
			int r = i;
			if ((i == 1 || i == 2) && (t == "abc") && (c[0] && c[1] && c[2]))
				r = 3 - r;
			for (int j = 0; j < c[r]; j++)
				cout << (char)('a' + r);
		}
		cout << '\n';
	}
	return 0;
}