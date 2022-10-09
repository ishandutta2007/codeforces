#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string monom(int x) {
	x *= -1;
	if (x < 0) {
		return string("(t") + to_string(x) + ")";
	} else if (x == 0) {
		return "t";
	} else {
		return string("(t+") + to_string(x) + ")";
	}
}

string aps(int x) {
	return string("abs(") + monom(x) + ")";
}

string add(string a, string b) {
	return "(" + a + "+" + b + ")";
}

string sub(string a, string b) {
	return "(" + a + "-" + b + ")";
}

string flip(string a) {
	return "(0-" + a + ")";
}

string pik(int x) {
	string p = add(aps(x-1), aps(x+1));
	string q = add(aps(x), aps(x));
	return sub(p, q);
}

string pik(int x, int y) {
	if (y < 0)
		return flip(pik(x, -y));
	string s = pik(x);
	return "(" + s + "*" + to_string(y/2) + ")";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	string f = "0", g = "0";

	while (n--) {
		int x, y, r;
		cin >> x >> y >> r;
		for (int i=x-1; i<=x+1; i++) {
			for (int j=y-1; j<=y+1; j++) {
				if (i % 2 == 0 && j % 2 == 0) {
					f = add(f, pik(n, i));
					g = add(g, pik(n, j));
					i = j = 123123;
					break;
				}
			}
		}
	}

	cout << f << '\n';
	cout << g << '\n';
}