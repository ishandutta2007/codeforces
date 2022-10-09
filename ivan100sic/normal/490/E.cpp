#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool ok(string s, string p) {
	if (p.size() > s.size())
		return true;
	if (p.size() < s.size())
		return false;
	return p > s;
}

int n;
string s[100005];

void no() {
	cout << "NO\n";
	exit(0);
}

string greedy_popuni(string s) {
	for (char& x : s)
		if (x == '?')
			x = '9';
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> s[i];

	string last = "";
	for (int i=0; i<n; i++) {
		// namesti
		int k = s[i].size();
		for (int j=0; j<k; j++) {
			if (s[i][j] == '?') {
				// nadji najmanju cifru koja moze da stane
				int done = 0;
				for (char x=(j ? '0' : '1'); x<='9'; x++) {
					string p = s[i];
					p[j] = x;
					if (ok(last, greedy_popuni(p))) {
						s[i] = p;
						done = 1;
						break;
					}
				}
				if (!done)
					no();
			}
		}
		if (!ok(last, s[i]))
			no();
		last = s[i];
	}

	cout << "YES\n";
	for (int i=0; i<n; i++)
		cout << s[i] << '\n';
}