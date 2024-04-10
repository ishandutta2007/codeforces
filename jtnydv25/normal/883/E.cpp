#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
char done[256];
set<int> pos[256];

int main() {
	string hid, s;
	cin >> n >> hid >> m;
	for (int i=0; i<n; i++) {
		if (hid[i] != '*')
			done[hid[i]] = true;
	}
	int cnt = 0;
	while (m--) {
		cin >> s;
		bool flag = true;
		for (int i=0; s[i]; i++) {
			if ((hid[i] == '*' && done[s[i]]) || 
				(hid[i] != '*' && s[i] != hid[i]))
				flag = false;
		}
		if (flag) {
			cnt++;
			for (int i=0; s[i]; i++)
				if (hid[i] == '*')
					pos[s[i]].insert(m);
		}
	}
	if (cnt == 0) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	for (char c='a'; c<='z'; c++) {
		if (!done[c] && pos[c].size() == cnt)
			ans++;
	}
	cout << ans << endl;

	return 0;
}