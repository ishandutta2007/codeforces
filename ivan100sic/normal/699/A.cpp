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

	int n;
	cin >> n;
	string s;
	cin >> s;
	int lastR = -1, sol = 1123123123;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		if (s[i] == 'L') {
			if (lastR != -1) {
				sol = min(sol, x - lastR);
			}
		} else {
			lastR = x;
		}
	}
	if (sol == 1123123123)
		sol = -2;
	cout << sol/2 << '\n';
}