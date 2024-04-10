#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string c, a, b;
int dp[1005][55][55];
int n, u, v;

int pre[2][55][26];

template<class T>
void calc_pre(string s, T pre) {
	int n = s.size();
	for (int i=0; i<=n; i++) {
		for (char x='a'; x<='z'; x++) {
			string p = s.substr(0, i) + x;
			int ok = 0;
			for (int j=0; j<=i+1; j++) {
				int l = i+1-j;
				if (p.substr(j) == s.substr(0, l)) {
					ok = l;
					break;
				}
			}
			pre[i][x-'a'] = ok;
		}
	}
}

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> c >> a >> b;
	n = c.size();
	u = a.size();
	v = b.size();
	memset(dp, 254, sizeof(dp));
	dp[0][0][0] = 0;

	calc_pre(a, pre[0]);
	calc_pre(b, pre[1]);

	for (int i=0; i<n; i++) {
		for (int j=0; j<=u; j++) {
			for (int k=0; k<=v; k++) {
				char lo = c[i];
				char hi = c[i];
				if (lo == '*') {
					lo = 'a';
					hi = 'z';
				}
				for (char x=lo; x<=hi; x++) {
					int val = dp[i][j][k];
					int jj = pre[0][j][x-'a'];
					int kk = pre[1][k][x-'a'];
					if (jj == u)
						val++;
					if (kk == v)
						val--;
					mx(dp[i+1][jj][kk], val);
				}
			}
		}
	}

	int sol = -123123123;
	for (int j=0; j<=u; j++) {
		for (int k=0; k<=v; k++) {
			mx(sol, dp[n][j][k]);
		}
	}

	cout << sol << '\n';
}