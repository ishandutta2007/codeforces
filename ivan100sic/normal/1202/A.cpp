#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int tz(string& s) {
	reverse(s.begin(), s.end());
	int p = 0;
	while (s[p] == '0')
		p++;
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		int x = tz(a), y = tz(b), z;
		if (x >= y) {
			z = x - y;
		} else {
			for (int i=y; i<(int)a.size(); i++)
				if (a[i] == '1') {
					z = i-y;
					break;
				}
		}
		cout << z << '\n';
	}
}

/*
10001 x = 0
011 y = 1

1010101010101
11110000

1010101010101
00001111

*/