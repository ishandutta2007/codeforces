#include <bits/stdc++.h>
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
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			c++;
		}
		if (isdigit(x) && x % 2 == 1) {
			c++;
		}
	}

	cout << c;
}