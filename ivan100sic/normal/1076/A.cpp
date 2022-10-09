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

	int n;
	cin >> n;

	string s;
	cin >> s;

	for (int i=0; i<n-1; i++) {
		if (s[i] > s[i+1]) {
			cout << s.substr(0, i) << s.substr(i+1) << '\n';
			return 0;
		}
	}

	cout << s.substr(0, n-1) << '\n';
}