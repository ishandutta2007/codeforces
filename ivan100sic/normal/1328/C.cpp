// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

	int t;
	cin >> t;
	while (t--) {
		string s;
		int n;
		cin >> n >> s;
		string a(n, '0');
		string b = a;
		bool off = false;
		a[0] = b[0] = '1';
		for (int i=1; i<n; i++) {
			if (off) {
				b[i] = s[i];
			} else {
				if (s[i] == '1') {
					a[i] = '1';
					off = 1;
				} else if (s[i] == '2') {
					a[i] = b[i] = '1';
				}
			}
		}
		cout << a << '\n' << b << '\n';
	}
}

// I will still practice daily...