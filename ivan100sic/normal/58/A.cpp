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

	string h = "hello";
	int p = 0;
	string s;

	cin >> s;
	for (char x : s) {
		if (x == h[p]) {
			p++;
			if (p == 5) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}