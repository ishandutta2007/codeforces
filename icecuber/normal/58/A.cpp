#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	string h = "hello";
	int a = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == h[a]) a++;
		if (a == 5) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}