#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

int main()
{

	int n, m;
	cin >> n >> m;

	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	int x;
	cin >> x;
	--x;

	string pattern = s[x];
	vector<char> used(n, false);
	used[x] = true;

	for (int i = 1; i < m; ++i) {
		cin >> x;
		--x;
		used[x] = true;
		if (sz(s[x]) != sz(pattern)) {
			cout << "No\n";
			return 0;
		}
		for (int j = 0; j < sz(pattern); ++j) {
			if (pattern[j] != s[x][j]) {
				pattern[j] = '?';
			}
		}
	}

	bool ok = true;
	for (int i = 0; i < n; ++i) {
		if (sz(pattern) == sz(s[i]) && !used[i]) {
			bool match = true;
			for (int j = 0; j < sz(pattern); ++j) {
				if (pattern[j] != '?' && pattern[j] != s[i][j]) {
					match = false;
				}
			}
			if (match) {
				ok = false;
			}
		}
	}

	if (ok) {
		cout << "Yes\n";
		cout << pattern << "\n";
	} else {
		cout << "No\n";
	}

}