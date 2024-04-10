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

	string s;
	cin >> s;
	int c = 0;
	for (char x : s) {
		if (x == 'H' || x == 'Q' || x == '9') {
			c++;
		}
	}
	cout << (c ? "YES" : "NO");
}