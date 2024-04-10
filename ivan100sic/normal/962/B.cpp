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
 
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	int sol = 0;
	for (int i=0; i<n; i++) {
		if (s[i] == '.') {
			bool ma = 0, mb = 0;
			if ((i == 0 || s[i-1] != 'a') && a > 0) {
				ma = 1;
			}
			if ((i == 0 || s[i-1] != 'b') && b > 0) {
				mb = 1;
			}
 
			if (ma && mb) {
				if (a > b) {
					s[i] = 'a';
					a--;
					sol++;
				} else {
					s[i] = 'b';
					b--;
					sol++;
				}
			} else if (ma) {
				s[i] = 'a';
				a--;
				sol++;
			} else if (mb) {
				s[i] = 'b';
				sol++;
				b--;
			}
		}
	}
	cout << sol << '\n';
}