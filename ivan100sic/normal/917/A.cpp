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
	int z = 0, n = s.size();
	for (int i=0; i<n; i++) {
		int o=0, u=0, p=0;
		for (int j=i; j<n; j++) {
			if (s[j] == ')') {
				if (o > 0) {
					o--;
				} else if (u > 0) {
					u--;
				} else if (p > 0) {
					p--;
					u++;
				} else {
					break;
				}
			} else if (s[j] == '(') {
				o++;
			} else if (s[j] == '?') {
				if (o > 0) {
					p++;
					o--;
				} else {
					u++;
				}
			}
			if ((j-i+1) % 2 == 0 && o == 0) {
				// cerr << i << ' ' << j << ' ' << s.substr(i, j-i+1) << '\n';
				z++;
			}
		}
	}
	cout << z << '\n';
}