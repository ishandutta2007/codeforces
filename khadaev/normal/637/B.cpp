#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> s(n);
	unordered_set<string> names;
	for (int i = 0; i < n; ++i) cin >> s[i];
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; ++i) {
		if (names.count(s[i]) == 0) {
			cout << s[i] << '\n';
			names.insert(s[i]);
		}
	}
}