// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		string s;
		cin >> s;
		vector<int> a(n+1);
		map<int, int> f;
		for (int i=0; i<n; i++) {
			a[i+1] = a[i] + (s[i] == '0' ? 1 : -1);
			f[a[i]]++;
		}
		if (a[n] == 0) {
			if (f[x] > 0) {
				cout << "-1\n";
			} else {
				cout << "0\n";
			}
		} else {
			int c = 0;
			for (int i=0; i<n; i++) {
				if ((x - a[i]) % a[n] == 0 && (x - a[i]) / a[n] >= 0)
					c++;
			}
			cout << c << '\n';
		}
	}
}