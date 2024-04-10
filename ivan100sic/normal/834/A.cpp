#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int ord(char x) {
	if (x == '^')
		return 0;
	else if (x == '>')
		return 1;
	else if (x == 'v')
		return 2;
	else if (x == '<')
		return 3;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	char x, y;
	cin >> x >> y;
	int p = ord(x), q = ord(y), n;
	cin >> n;

	n %= 4;

	bool cw = false, ccw = false;
	if ((p+n) % 4 == q)
		cw = true;
	if ((p+8-n) % 4 == q)
		ccw = true;
	if (cw && ccw)
		cout << "undefined\n";
	else if (cw)
		cout << "cw\n";
	else if (ccw)
		cout << "ccw\n";
}