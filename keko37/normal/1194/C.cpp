#include<bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int tc, n, m;
string s, t, p;
int cnt[MAXN];

int main () {
	cin >> tc;
	while (tc--) {
		cin >> s >> t >> p;
		memset(cnt, 0, sizeof cnt);
		for (auto z : p) {
			cnt[z - 'a']++;
		}
		n = s.size(); m = t.size();
		int p = 0, moze = 1;
		for (auto z : s) {
			while (p < m && t[p] != z) {
				cnt[t[p] - 'a']--;
				p++;
			}
			if (p == m) moze = 0;
			p++;
		}
		while (p < m) {
			cnt[t[p] - 'a']--;
			p++;
		}
		for (int i=0; i<26; i++) {
			if (cnt[i] < 0) moze = 0;
		}
		if (moze) cout << "YES\n"; else cout << "NO\n";
	}
	return 0;
}