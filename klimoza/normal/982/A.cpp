#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n;
	cin >> n;
	int ans = floor(n / 2);
	string s;
	cin >> s;
	if (n % 2 == 1) {
		ans++;
	}
	bool fl = true;
	if (s[0] == '0' and n == 1) {
		fl = false;
	}
	else if (n != 1 and s[1] == '0' and s[0] == '0') {
		fl = false;
	}
	for (int i = 1; i < n; i++) {
		if (!fl) break;
		if (s[i] == s[i - 1] and s[i] == '1') {
			fl = false;
			break;
		}
		if (i != n - 1 and s[i - 1] == '0' and s[i + 1] == '0' and s[i] == '0') {
			fl = false;
			break;
		}
		if (i == n - 1 and s[i] == '0' and s[i - 1] == '0') {
			fl = false;
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