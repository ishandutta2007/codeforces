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
	int x=0, y=0, z=0;
	for (char c : s) {
		if (!x && c == 'F')
			continue;
		x++;
		if (c == 'F') {
			z++;
			y = max(y+1, x-z);
		}
	}
	cout << y << '\n';
}