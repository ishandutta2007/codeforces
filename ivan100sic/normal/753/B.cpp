#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	char y = 0;

	for (char x='0'; x<='9'; x++) {
		cout << string({x, x, x, x}) << '\n' << flush;
		int a, b;
		cin >> a >> b;
		if (a == 0) {
			y = x;
			break;
		}
	}

	char s[5] = {y, y, y, y, 0};

	for (int i=0; i<4; i++) {
		for (char x='0'; x<='9'; x++) {
			s[i] = x;
			cout << s << '\n' << flush;
			int a, b;
			cin >> a >> b;
			if (a == i+1) {
				break;
			}
		}
	}
}