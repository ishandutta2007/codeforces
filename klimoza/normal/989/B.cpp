#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;


int main() {
	int n, p;
	cin >> n >> p;
	string s;
	int ans = -1;
	int type = 0;
	cin >> s;
	for (int i = 0; i < n - p; i++) {
		if (s[i] == s[i + p] and s[i] != '.') {
			continue;
		}
		else if (s[i] == s[i + p]) {
			type = 1;
			ans = i;
		}
		else if (s[i] == '.') {
			type = -((s[i + p] + 1) % 2);
			ans = i;
		}
		else {
			type = -((s[i] + 1) % 2);
			ans = i + p;
		}
	}
	if (ans == -1) {
		cout << "No\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (i == ans) {
				if (type == 1) {
					cout << 0;
				}
				else {
					cout << abs(type);
				}
			}
			else if (i == ans + p and type == 1) {
				cout << 1;
			}
			else if (s[i] == '.') {
				cout << 0;
			}
			else {
				cout << s[i];
			}
		}
	}
	//system("pause");
	return 0;
}