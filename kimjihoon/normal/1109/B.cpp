#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	char c = s[0];
	bool f = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != c && !(s.length() % 2 == 1 && i == s.length() / 2)) {
			f = true;
			break;
		}
	}
	if (!f) {
		cout << "Impossible" << '\n';
		return 0;
	}
	for (int i = 1; i < s.length(); i++) {
		bool pf = false;
		string ts = "";
		for (int j = 0; j < s.length(); j++) {
			ts += s[(i + j) % s.length()];
			if (ts[j] != s[j])
				pf = true;
		}
		if (!pf) continue;
		for (int j = 0; j < s.length() / 2; j++)
			if (ts[j] != ts[s.length() - j - 1]) {
				pf = false;
				break;
			}
		if (pf) {
			cout << 1 << '\n';
			return 0;
		}
	}
	cout << 2 << '\n';	
	return 0;
}