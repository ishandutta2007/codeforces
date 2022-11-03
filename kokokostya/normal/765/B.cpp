#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

int main() {
	string s;
	cin >> s;
	vector<bool> a(26);
	for (int i = 0; i < s.length(); i++) {
		a[s[i] - 'a'] = 1;
		if (s[i] != 'a' && !a[s[i] - 'a' - 1]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}