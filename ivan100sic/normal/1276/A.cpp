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
		cin >> s;
		int n = s.size();
		for (int i=0; i<=n-5; i++)
			if (s.substr(i, 5) == "twone")
				s[i+2] = 0;
		for (int i=0; i<=n-3; i++) {
			string t = s.substr(i, 3);
			if (t == "one" || t == "two")
				s[i+1] = 0;
		}
		cout << count(s.begin(), s.end(), 0) << '\n';
		for (int i=0; i<n; i++)
			if (!s[i])
				cout << i+1 << ' ';
		cout << '\n';
	}
}