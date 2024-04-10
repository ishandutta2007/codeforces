#include <bits/stdc++.h>
using namespace std;

string s;
int p[3005], dp[3005], n;

bool b[3005][3005];

bool consonant(char x) {
	if (x == 'a') {
		return false;
	}
	if (x == 'e') {
		return false;
	}
	if (x == 'i') {
		return false;
	}
	if (x == 'o') {
		return false;
	}
	if (x == 'u') {
		return false;
	}
	return true;
}

bool bad(char x, char y, char z) {
	return consonant(x) && consonant(y) && consonant(z) && !(x == y && y == z);
}

bool skok[3005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	s = string("a") + s;

	for (int i=1; i<=n; i++) {
		for (int j=i+2; j<=n; j++) {
			if (b[i][j-1] || bad(s[j], s[j-1], s[j-2])) {
				b[i][j] = true;
			}
		}
	}

	for (int i=1; i<=n; i++) {
		dp[i] = 123123213;
		for (int j=0; j<i; j++) {
			if (dp[j] + 1 < dp[i] && !b[j+1][i]) {
				dp[i] = dp[j] + 1;
				p[i] = j;
			}
		}
	}

	cerr << dp[n] << '\n';

	for (int x = n; x; x = p[x]) {
		cerr << x << '\n';
		skok[x] = true;
	}

	for (int i=1; i<=n; i++) {
		cout << s[i];
		if (skok[i]) {
			cout << ' ';
		}
	}
}