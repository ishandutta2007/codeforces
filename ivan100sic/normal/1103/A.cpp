#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int state = 0;
	for (char x : s) {
		if (x == '0') {
			if (state & 1) {
				cout << "3 1\n";
			} else {
				cout << "1 1\n";
			}
			state ^= 1;
		} else {
			if (state & 2) {
				cout << "4 1\n";
			} else {
				cout << "4 3\n";
			}
			state ^= 2;
		}
	}
}