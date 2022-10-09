#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s;
int n;
ll dp[105][105], a[105];

ll inner0[105][105], inner1[105][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	s = string(" ") + s + string(" ");

	for (int l=n; l>=1; l--) {

		memset(inner0, 128, sizeof(inner0));						
		memset(inner1, 128, sizeof(inner1));

		inner0[l-1][0] = inner1[l-1][0] = 0;

		for (int i=l; i<=n; i++) {
			// mogu da samo uzmem ovo ako je kec
			if (s[i] == '1')
				for (int x=1; x<=i-l+1; x++)
					inner1[i][x] = max(inner1[i][x], inner1[i-1][x-1]);
			// spoji unazad
			for (int x=0; x<=i-l+1; x++)
				for (int j=i; j>=l; j--)
					inner1[i][x] = max(inner1[i][x], inner1[j-1][x] + dp[j][i]);
		}

		for (int i=l; i<=n; i++) {
			// mogu da samo uzmem ovo ako je kec
			if (s[i] == '0')
				for (int x=1; x<=i-l+1; x++)
					inner0[i][x] = max(inner0[i][x], inner0[i-1][x-1]);
			// spoji unazad
			for (int x=0; x<=i-l+1; x++)
				for (int j=i; j>=l; j--)
					inner0[i][x] = max(inner0[i][x], inner0[j-1][x] + dp[j][i]);
		}

		for (int r=l; r<=n; r++) {
			for (int x=0; x<=r-l+1; x++) {
				dp[l][r] = max(dp[l][r], inner0[r][x] + a[x]);
				dp[l][r] = max(dp[l][r], inner1[r][x] + a[x]);
			}
		}
	}
	cout << dp[1][n] << '\n';
}