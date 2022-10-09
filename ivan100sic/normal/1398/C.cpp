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
		map<int, int> m;
		m[0] = 1;
		int z = 0;
		ll u = 0;
		int n;
		string s;
		cin >> n >> s;
		for (char c : s) {
			int x = c-48;
			z += x - 1;
			u += m[z]++;
		}
		cout << u << '\n';
	}
}