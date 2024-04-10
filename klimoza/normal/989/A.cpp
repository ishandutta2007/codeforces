#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;


int main() {
	string s;
	cin >> s;
	bool fl = false;
	for (int i = 1; i < s.length() - 1; i++) {
		if (s[i] == 'A' and (s[i - 1] == 'B' and (s[i + 1] == 'C') or (s[i - 1] == 'C' and s[i + 1] == 'B'))) {
			fl = true;
			break;
		}
		if (s[i] == 'B' and (s[i - 1] == 'A' and (s[i + 1] == 'C') or (s[i - 1] == 'C' and s[i + 1] == 'A'))) {
			fl = true;
			break;
		}
		if (s[i] == 'C' and (s[i - 1] == 'A' and (s[i + 1] == 'B') or (s[i - 1] == 'B' and s[i + 1] == 'A'))) {
			fl = true;
			break;
		}
	}
	if (fl) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	//system("pause");
	return 0;
}