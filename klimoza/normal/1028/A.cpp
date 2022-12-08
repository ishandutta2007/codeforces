#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	string s;
	int x = 0;
	int y = 0;
	int len = 0;
	bool fl = false;
	bool bl = false;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (!bl && s[j] == 'B') {
				x = i + 1;
				y = j + 1;
				bl = true;
			}
			if (bl && s[j] == 'W') {
				fl = true;
				len = j + 1 - y;
				break;
			}
		}
		if (bl && !fl) {
			len = m + 1 - y;
			break;
		}
		if (fl) break;
	}
	//cout << x << " " << y << " " << len << "\n";
	cout << x + (len - 1) / 2 << " " << y + (len - 1) / 2 << "\n";
	//system("pause");
	return 0;
}