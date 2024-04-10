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

	set<char> s;
	int x, y, z;
	cin >> x >> y >> z;
	for (int u=0; u<=z; u++) {
		int v = z-u;
		int q = x-y+u-v;
		if (q < 0)
			s.insert('-');
		else if (q > 0)
			s.insert('+');
		else
			s.insert('0');
	}

	if (s.size() > 1)
		cout << "?";
	else
		cout << *s.begin();
	cout << '\n';
}