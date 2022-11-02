#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	bool f = false;
	for (int i = 0; i < 5; i++) {
		string t; cin >> t;
		if (t[0] == s[0] || t[1] == s[1])
			f = true;
	}
	if (f) cout << "YES" << '\n';
	else cout << "NO" << '\n';
	return 0;
}