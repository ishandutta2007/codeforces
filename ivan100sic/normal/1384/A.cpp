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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}

		string s(55, 'b');
		cout << s << '\n';
		for (int i=0; i<n; i++) {
			s[a[i]] ^= 1;
			cout << s << '\n';
		}
	}
}