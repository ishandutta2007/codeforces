#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	while (t--) {
		int flag = 0;
		for (int i = 0; i < n-1; i++) {
			if (!flag and s[i] == 'B' and s[i+1] == 'G') {
				swap(s[i], s[i+1]);
				flag = 1;
			} else flag = 0;
		}
	}
	cout << s << endl;
	return 0;
}