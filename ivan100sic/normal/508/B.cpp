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

	string s;
	cin >> s;

	int n = s.size();
	for (int i=0; i<n; i++) {
		if (s[i] % 2 == 0 && s[i] < s[n-1]) {
			swap(s[i], s[n-1]);
			cout << s << '\n';
			return 0;
		}
	}

	for (int i=n-2; i>=0; i--) {
		if (s[i] % 2 == 0) {
			swap(s[i], s[n-1]);
			cout << s << '\n';
			return 0;
		}
	}

	cout << "-1\n";
}