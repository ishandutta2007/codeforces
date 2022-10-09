#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

short int lsp[8005][8005], su[8005][8005];
int dp[8005];

int dgts[8005];

void find_dgts() {
	for (int i=1; i<=8000; i++) {
		dgts[i] = 1 + dgts[i / 10];
	}
}

int main() {
	find_dgts();

	string s;
	cin >> s;
	int n = s.size();
	s = string(" ") + s;

	memset(lsp, 255, sizeof(lsp));

	for (int i=1; i<=n; i++) {
		lsp[i][i] = 0;
		for (int j=i+1; j<=n; j++) {
			int kand = lsp[i][j-1] + 1;
			while (kand > 0) {
				if (s[i+kand-1] == s[j]) {
					lsp[i][j] = kand;
					break;
				} else {
					kand = lsp[i][i+kand-2] + 1;
				}
			}
			if (kand == 0) {
				lsp[i][j] = 0;
			}
		}
	}

	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			int v = (j-i+1) - lsp[i][j];
			if ((j-i+1) % v) {
				su[i][j] = j-i+1;
			} else {
				su[i][j] = v;
			}
		}
	}

	dp[0] = 0;
	for (int i=1; i<=n; i++) {
		int x = dp[i-1] + 2;
		for (int l=1; l<=i; l++) {
			x = min(x, dp[i-l] + su[i-l+1][i] + dgts[l / su[i-l+1][i]]);
		}
		dp[i] = x;
	}

	cout << dp[n];
}