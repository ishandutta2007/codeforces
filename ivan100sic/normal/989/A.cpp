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

	for (int i=0; i<(int)s.size(); i++) {
		map<char, int> m;
		for (int j=max(0, i-1); j<=min(i+1, (int)s.size() - 1); j++) {
			m[s[j]]++;
		}
		if (m['A'] && m['B'] && m['C']) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No\n";
}