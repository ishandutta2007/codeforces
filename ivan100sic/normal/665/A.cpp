// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int a, ta, b, tb;
	cin >> a >> ta >> b >> tb;

	string s;
	cin >> s;
	int ts = 0;
	ts += (s[0] - '0') * 600;
	ts += (s[1] - '0') * 60;
	ts += (s[3] - '0') * 10;
	ts += (s[4] - '0') * 1;

	int te = ts + ta, z = 0;

	for (int x=300; x<1440; x+=b) {
		int y = x + tb;
		if (max(x, ts) < min(y, te))
			z++;
	}

	cout << z << '\n';
}