// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string s;
int n;

struct state {
	string pref, suff;
	char nx = 0;
	int len = 0;
	int eq = 0;

	void prepend(char c) {
		len++;
		if (pref.size() && c != pref[0]) {
			nx = pref[0];
			eq = 1;
		} else {
			eq++;
		}

		pref = string(1, c) + pref;
		if (suff.size()) {
			pref.pop_back();
		} else if (pref.size() == 11) {
			suff = pref.substr(9);
			pref.pop_back();
		}
	}

	bool operator< (const state& b) const {
		if (!len || !b.len) {
			return len < b.len;
		}

		if (pref[0] != b.pref[0]) return pref[0] < b.pref[0];

		if (eq < b.eq) {
			return nx < pref[0];
		} else if (eq > b.eq) {
			return pref[0] < b.nx;
		} else {
			return nx < b.nx;
		}
	}
};

state dp[100005];
string ans[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> s;
	n = s.size();

	dp[n] = {"", "", 0, 0};

	for (int i=n-1; i>=0; i--) {
		dp[i] = dp[i+1];
		dp[i].prepend(s[i]);
		if (i+1 < n && s[i] == s[i+1]) {
			state t = dp[i+2];
			dp[i] = min(dp[i], t);
		}
		ans[i] = to_string(dp[i].len) + " " + (dp[i].suff.size() ? dp[i].pref.substr(0, 5) + "..." + dp[i].suff : dp[i].pref);
	}

	for (int i=0; i<n; i++) cout << ans[i] << '\n';
}