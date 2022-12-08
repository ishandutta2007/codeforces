#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;


int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		ans += int(s[i]) - int('0');
	}
	bool fl = false;
	if (ans == 0) fl = true;
	for (int i = 1; i <= sqrt(ans); i++) {
		if (fl) break;
		if (ans % i != 0) continue;
		int cur = 0;
		int f = 0;
		for (int j = 0; j < s.length(); j++) {
			cur += int(s[j]) - int('0');
			if (cur == i) {
				cur = 0;
				f++;
			}
			if (cur > i) {
				cur = -1;
				break;
			}
		}
		if (cur != -1 && f > 1) {
			fl = true;
			break;
		}
		if (i == 1) continue;
		cur = 0;
		f = 0;
		for (int j = 0; j < s.length(); j++) {
			cur += int(s[j]) - int('0');
			if (cur == ans / i) {
				cur = 0;
				f++;
			}
			if (cur > ans / i) {
				cur = -1;
				break;
			}
		}
		if (cur != -1 && f > 1) {
			fl = true;
			break;
		}
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