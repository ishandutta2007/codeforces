#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	for (int i=0; i<=n-26; i++) {
		set<char> pending;
		for (char x='A'; x<='Z'; x++)
			pending.insert(x);
		bool ok = true;

		string repl;
		for (int j=i; j<i+26; j++) {
			if (s[j] != '?') {
				if (pending.count(s[j])) {
					pending.erase(s[j]);
				} else {
					ok = false;
				}
			}
		}

		if (ok) {
			for (int j=i; j<i+26; j++) {
				if (s[j] != '?') {
					repl += s[j];
				} else {
					char x = *pending.begin();
					repl += x;
					pending.erase(x);
				}
			}
			for (int j=0; j<n; j++) {
				if (s[j] == '?') {
					s[j] = 'A';
				}
			}
		}

		if (ok) {
			cout << s.substr(0, i) << repl << s.substr(i+26) << '\n';
			return 0;
		}
	}

	cout << "-1\n";
}