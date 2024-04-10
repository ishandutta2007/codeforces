#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[11], m;
int dp[11][2][11];
int c[7];

int lucky(int x) {
	return x == 4 || x == 7;
}

const int M = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	{
		int t;
		cin >> t;
		t++;
		string s = to_string(t);
		m = s.size();
		for (int i=0; i<m; i++)
			a[i] = s[i] - '0';
	}

	dp[0][0][0] = 1;
	for (int i=0; i<m; i++) {
		for (int f=0; f<2; f++) {
			for (int j=0; j<11; j++) {
				if (!dp[i][f][j])
					continue;
				for (int d=0; d<10; d++) {
					if (!f && d > a[i])
						continue;
					dp[i+1][f || (d < a[i])][j + lucky(d)] += dp[i][f][j];
				}
			}
		}
	}

	dp[m][1][0]--;

	int sol = 0;

	for (c[0]=0; c[0]<=m; c[0]++)
	for (c[1]=0; c[1]<=m; c[1]++)
	for (c[2]=0; c[2]<=m; c[2]++)
	for (c[3]=0; c[3]<=m; c[3]++)
	for (c[4]=0; c[4]<=m; c[4]++)
	for (c[5]=0; c[5]<=m; c[5]++)
	for (c[6]=0; c[6]<=m; c[6]++)
	{
		int p = 1;
		int raz = 2*c[0];
		for (int i=0; i<7; i++) {
			int v = dp[m][1][c[i]];
			raz -= c[i];
			if (raz <= 0)
				break;
			for (int j=0; j<i; j++)
				if (c[j] == c[i])
					v--;
			p = p * 1ll * v % M;
		}
		if (raz > 0) {
			sol += p;
			if (sol >= M)
				sol -= M;
		}
	}
	cout << sol << '\n';
}