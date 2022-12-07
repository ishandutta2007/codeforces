#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
	//freopen("in", "")

	string s, ans;
	cin >> s;

	
	while (s.size() >= 3) {
		if (s.substr(0, 3) == "WUB") {
			s = s.substr(3);
			ans += ' ';
		} else {
			ans += s[0];
			s = s.substr(1);
		}
	}
	ans += s;

	while (s.size() > 0 && s[s.size() - 1] == ' ') s = s.substr(0, s.size() - 1);

	bool wasWord = false;
	for (int i = 0; i < ans.size(); ++i)
		if (ans[i] == ' ') {
			if (wasWord && (i != 0 && ans[i - 1] != ' ')) cout << ans[i];
		} else {
			cout << ans[i];
			wasWord = true;
		}
	cout << endl;

	return 0;
}