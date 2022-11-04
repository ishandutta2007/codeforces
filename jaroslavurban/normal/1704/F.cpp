#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

int n = 500500;
vector<int> dp(n);

const string A = "Alice";
const string B = "Bob";

void ProGamerMove() {
	int n; cin >> n;
	string s; cin >> s;
	int cntR = count(s.begin(), s.end(), 'R');
	string W;
	if (2 * cntR == n) {
		int xr = 0;
		int i = 0;
		while (1) {
			while (i + 1 < n && s[i] == s[i + 1]) ++i;
			if (i == n - 1) break;
			int l = 0;
			while (i + 1 < n && s[i] != s[i + 1]) ++i, ++l;
			xr ^= dp[l];
		}
		W = xr ? A : B;
	} else W = 2 * cntR > n ? A : B;
	cout << W << '\n';
}


signed main(){
	dp[1] = 1;
	for (int i = 2; i < n; ++i) {
		set<int> nums;
		for (int j = 0, k = 0; k < 70 && j <= i - 3; ++j, ++k)
			nums.insert(dp[j] ^ dp[i - 3 - j]);
		nums.insert(dp[i - 2]);
		while (nums.find(dp[i]) != nums.end()) ++dp[i];
	}
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}