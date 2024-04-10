#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
const int maxchar = 26;
int charcount[maxchar][maxn], cow[maxchar];

void reset() {
	for (int i = 0; i < maxchar; ++i) {
		memset(charcount[i], 0, maxn);
		cow[i] = 0;
	}
}

void solve() {
	reset();
	int n, m;
	string s;
	cin >> n >> m;
	cin >> s;
	++charcount[s[0] - 97][0];
	++cow[s[0] - 97];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (s[i] - 97 == j) ++charcount[j][i];
			charcount[j][i] += charcount[j][i - 1];
		}
		++cow[s[i] - 97];
	}
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		for (int j = 0; j < 26; ++j) {
			if (charcount[j][a - 1]) cow[j] += charcount[j][a - 1];
		}
	}
	for (int i : cow) cout << i << ' ';
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int t;
	cin >> t;
	while (t > 0) {
		solve();
		--t;
	}
}