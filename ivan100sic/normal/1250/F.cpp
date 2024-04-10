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
		int k, z = 0;
		string s;
		cin >> k >> s;
		for (int i=0; i<k; i++) {
			int l = -1;
			if (s[i] == 'P') {
				for (int j=0; j<i; j++) {
					if (s[j] == 'A') {
						l = j;
					}
				}
				if (l != -1) {
					z = max(z, i-l);
				}
			}
		}
		cout << z << '\n';
	}
}