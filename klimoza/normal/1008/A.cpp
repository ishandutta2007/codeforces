#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	string s;
	cin >> s;
	bool fl = true;
	int n = s.length();
	for (int i = 1; i < n; i++) {
		if (s[i] != 'a' and s[i] != 'o' and s[i] != 'u' and s[i] != 'i' and s[i] != 'e') {
			if (s[i - 1] != 'a' and s[i - 1] != 'o' and s[i - 1] != 'u' and s[i - 1] != 'i' and s[i - 1] != 'e' and s[i - 1] != 'n') {
				fl = false;
				break;
			}
		}
	}
	if (s[n - 1] != 'a' and s[n - 1] != 'o' and s[n - 1] != 'u' and s[n - 1] != 'i' and s[n - 1] != 'e' and s[n - 1] != 'n') {
		fl = false;
	}
	if (fl) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	//system("pause");
	return 0;
}