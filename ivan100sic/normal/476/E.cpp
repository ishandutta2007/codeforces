#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s, p;

int jmp[2005];
int dp[2005][2005];

int& mx(int& x, int y) {
	return x = max(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> p;
	n = s.size();
	m = p.size();

	for (int i=0; i<n; i++) {
		int k = 0;
		for (int j=i; j<n; j++) {
			if (k == m) {
				jmp[i] = j;
				break;
			}
			if (s[j] == p[k])
				k++;
		}
		if (!jmp[i] && k == m) {
			jmp[i] = n;
		}
		cerr << i << ' ' << jmp[i] << "\n";
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<=i; j++) {
			mx(dp[i+1][j+1], dp[i][j]);
			mx(dp[i+1][j], dp[i][j]);
			if (jmp[i] > 0) {
				mx(dp[jmp[i]][j + jmp[i] - i - m], dp[i][j] + 1);
			}
		}
	}

	for (int i=0; i<=n; i++)
		cout << dp[n][i] << " \n"[i == n];
}