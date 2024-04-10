#include <iostream>
#include <string>
using namespace std;

int p[999];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s, t; cin >> s >> t;
	if (s.length() != t.length()) {
		cout << "No" << '\n';
		return 0;
	}
	p['a'] = p['e'] = p['i'] = p['o'] = p['u'] = 1;
	for (int i = 0; i < s.length(); i++)
		if (p[s[i]] != p[t[i]]) {
			cout << "No" << '\n';
			return 0;
		}
	cout << "Yes" << '\n';
	return 0;
}