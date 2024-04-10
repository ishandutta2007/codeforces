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
	int x = 0, z = 0;
	for (char c : s) {
		int y = c - 'a';
		int r = abs(y-x);
		r = min(r, 26-r);
		z += r;
		x = y;
	}
	cout << z << '\n';
}