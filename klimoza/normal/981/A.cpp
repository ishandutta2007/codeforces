#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


bool is_pal(string s) {
	int n = s.length();
	for (int i = 0; i < n / 2; i++) if (s[i] != s[n - i - 1]) return false;	
	return true;
}


int main() {
	string s = "";
	cin >> s;
	bool fl = is_pal(s);
	if (!fl) cout << s.length() << "\n";
	else {
		char j = s[0];
		bool bl = true;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] != j) bl = false;
		}
		if (bl) cout << 0 << "\n";
		else cout << s.length() - 1 << "\n";
	}
	//system("pause");
	return 0;
}