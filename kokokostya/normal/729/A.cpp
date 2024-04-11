#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (i + 2 < n && s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o') {
			cout << "***";
			i += 3;
			while (i + 1 < n && s[i] == 'g' && s[i + 1] == 'o')
				i += 2;
			i--;
		}
		else
			cout << s[i];
	}

	return 0;
}