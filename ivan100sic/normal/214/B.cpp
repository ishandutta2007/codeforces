// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int f[11];

void g() {
	string s;
	for (int i=0; i<10; i++) {
		while (f[i]--) s += char(i + 48);
	}

	sort(begin(s), end(s), greater<char>());
	if (s.size() > 1 && s[0] == '0') {
		s = "0";
	}
	
	cout << s << '\n';
	exit(0);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		f[x]++;
	}

	if (f[0] == 0) {
		cout << "-1\n";
		return 0;
	}

	// moze svi?
	int r = 0;
	for (int i=0; i<10; i++) {
		r += i * f[i];
	}

	if (r % 3 == 0) {
		// sve
		g();
	} else {
		// nadji ostatak r?
		for (int i=0; i<10; i++) {
			if (i % 3 == r % 3 && f[i] > 0) {
				f[i]--;
				g();
			}
		}

		// nadji dva sa ostatkom u zbiru r
		for (int i=0; i<10; i++) {
			for (int j=0; j<=i; j++) {
				bool ok = false;
				if (i == j) ok = f[i] >= 2;
				else ok = f[i] && f[j];

				if ((i+j) % 3 == r % 3 && ok) {
					f[i]--;
					f[j]--;
					g();
				}
			}
		}
	}
}