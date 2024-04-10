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
		int z = 0;
		while (1) {
			int j = 0;
			for (int i=0; i<(int)s.size()-1; i++) {
				if (s[i] != s[i+1]) {
					z++;
					j = 1;
					s.erase(i, 2);
					break;
				}
			}
			if (!j) break;
		}
		cout << (z % 2 == 0 ? "NET\n" : "DA\n");
	}
}