#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a;
set<int> e[26];
set<int> u[26];
bool vis[26];
bool ima[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		a.push_back(s);
	}

	bool ok = true;

	for (string s : a) {
		for (size_t i = 0; i + 1 < s.size(); i++) {
			e[s[i] - 'a'].insert(s[i+1] - 'a');
			u[s[i+1] - 'a'].insert(s[i] - 'a');
		}
		vector<int> br(26, 0);
		for (char x : s) {
			if (2 == ++br[x-'a']) {
				ok = false;
			}
			ima[x - 'a'] = true;
		}
	}

	for (int i=0; i<26; i++) {
		if (e[i].size() > 1 || u[i].size() > 1) {
			cout << "NO\n";
			return 0;
		}
	}

	if (!ok) {
		cout << "NO\n";
		return 0;
	}

	string sol;

	for (int i=0; i<26; i++) {
		if (!vis[i] && ima[i] && u[i].size() == 0) {
			int t = i;
			while (1) {
				vis[t] = true;
				sol += t + 'a';
				if (e[t].size() == 0) {
					break;
				} else {
					t = *e[t].begin();
				}
			}
		}
	}

	for (int i=0; i<26; i++) {
		if (ima[i] && !vis[i]) {
			ok = false;
		}
	}

	if (!ok) {
		cout << "NO\n";
		return 0;
	}

	cout << sol << '\n';




}