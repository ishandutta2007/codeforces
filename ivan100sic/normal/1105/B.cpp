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

	int n, k;
	string s;
	cin >> n >> k >> s;
	int sol = 0;
	for (char x='a'; x<='z'; x++) {
		int z = 0, y = 0;
		for (int i=0; i<n; i++) {
			if (s[i] == x) {
				y++;
				if (y == k) {
					y = 0;
					z++;
				}
			} else {
				y = 0;
			}
		}
		sol = max(sol, z);
	}
	cout << sol << '\n';
}