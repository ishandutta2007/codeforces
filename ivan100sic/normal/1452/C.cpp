// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		int a=0, b=0, z=0;

		for (char c : s) {
			if (c == '(') a++;
			else if (c == '[') b++;
			else if (c == ')') {
				if (a) {
					z++;
					a--;
				}
			} else {
				if (b) {
					z++;
					b--;
				}
			}
		}

		cout << z << '\n';
	}
}