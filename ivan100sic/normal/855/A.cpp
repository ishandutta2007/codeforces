#include <bits/stdc++.h>
using namespace std;

int n;
set<string> seen;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;
		if (seen.count(s)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
			seen.insert(s);
		}
	}
}