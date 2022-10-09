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
		if (state == 0) {
			if (x == '.')
				cout << 0;
			else
				state = 1;
		} else {
			if (x == '.') {
				cout << 1;
			} else {
				cout << 2;
			}
			state = 0;
		}
	}
}