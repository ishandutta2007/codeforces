#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

char a[9][9];
int x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j+=3) {
			string s;
			cin >> s;
			copy(s.begin(), s.end(), a[i]+j);
		}
	}

	cin >> x >> y;
	x--, y--;
	int p = x%3*3, q = y%3*3, f = 0;
	for (int i=p; i<p+3; i++) {
		for (int j=q; j<q+3; j++) {
			if (a[i][j] == '.') {
				f = 1;
			}
		}
	}

	if (!f) {
		for (int i=0; i<9; i++) {
			for (int j=0; j<9; j++) {
				if (a[i][j] == '.')
					a[i][j] = '!';
			}
		}
	} else {
		for (int i=p; i<p+3; i++) {
			for (int j=q; j<q+3; j++) {
				if (a[i][j] == '.') {
					a[i][j] = '!';
				}
			}
		}
	}

	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			cout << a[i][j];
			if (j == 2 || j == 5)
				cout << ' ';
		}
		if (i == 2 || i == 5)
				cout << '\n';
		cout << '\n';
	}
}