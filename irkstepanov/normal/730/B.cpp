#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

int main()
{

	int tt;
	cin >> tt;

	while (tt--) {
		int n;
		cin >> n;
		vector<int> a, b;
		for (int i = 0; i + 1 < n; i += 2) {
			cout << "? " << i + 1 << " " << i + 2 << "\n";
			cout.flush();
			char c;
			cin >> c;
			if (c == '>' || c == '=') {
				a.pb(i);
				b.pb(i + 1);
			} else {
				a.pb(i + 1);
				b.pb(i);
			}
		}
		if (n & 1) {
			a.pb(n - 1);
			b.pb(n - 1);
		}
		int minn = b[0];
		for (int i = 1; i < sz(b); ++i) {
			cout << "? " << minn + 1 << " " << b[i] + 1 << "\n";
			cout.flush();
			char c;
			cin >> c;
			if (c == '>') {
				minn = b[i];
			}
		}
		int maxx = a[0];
		for (int i = 1; i < sz(a); ++i) {
			cout << "? " << maxx + 1 << " " << a[i] + 1 << "\n";
			cout.flush();
			char c;
			cin >> c;
			if (c == '<') {
				maxx = a[i];
			}
		}
		cout << "! " << minn + 1 << " " << maxx + 1 << "\n";
	}

}