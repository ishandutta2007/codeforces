#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

static int n;
static string s;
static int dp[505][505];
static int gh[26][505];
static int ima[26];

static inline void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	memset(dp, 63, sizeof(dp));

	for (int l=n-1; l>=0; l--) {
		dp[l][l] = 0;
		// prvo izracunaj klizeci dp
		memset(gh, 63, sizeof(gh));
		for (int j=0; j<26; j++)
			gh[j][l] = 0;
		for (int r=l+1; r<=n; r++) {
			mn(gh[s[r-1]-'a'][r], gh[s[r-1]-'a'][r-1]);
			for (int j=0; j<26; j++) {
				for (int w=1; w<r-l; w++) {
					mn(gh[j][r], gh[j][r-w] + dp[r-w][r]);
				}
			}
		}
		// izracunaj pravi dp
		memset(ima, 0, sizeof(ima));
		for (int r=l+1; r<=n; r++) {
			ima[s[r-1]-'a'] = 1;
			for (int j=0; j<26; j++)
				mn(dp[l][r], gh[j][r] + ima[j]);
		}
	}
	cout << dp[0][n] << '\n';
}