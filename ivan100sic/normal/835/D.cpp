#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string s;
bool p[5005][5005];
int n;
int kid[5005];
int lcp[5005][5005];
int k[5005][5005];
int sol[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s;
	int n = s.size();

	s = string(".") + s + string(",");

	// p
	for (int i=n; i>=1; i--) {
		p[i][i] = true;
		if (i < n) {
			p[i][i+1] = s[i] == s[i+1];
		}
		for (int j=i+2; j<=n; j++) {
			p[i][j] = p[i+1][j-1] && (s[i] == s[j]);
		}
	}

	for (int i=n; i>=1; i--) {
		for (int j=i; j<=n; j++) {
			lcp[i][j] = lcp[i+1][j+1] + 1;
			if (s[i] != s[j]) {
				lcp[i][j] = 0;
			}
		}
	}

	for (int i=n; i>=1; i--) {
		for (int j=i; j<=n; j++) {
			int m = (i+j) / 2 + 1;
			int l = (j-i+1) / 2;

			if (lcp[i][m] >= l) {
				int k1 = k[i][i+l-1];
				int k2 = k[m][m+l-1];

				k[i][j] = (k1 & k2) << 1;
			}

			if (p[i][j]) {
				k[i][j] |= 2;
			}

			// cerr << i << ' ' << j << ' ' << k[i][j] << '\n';

			for (int b=0; b<20; b++) {
				if (k[i][j] & (1<<b)) {
					sol[b]++;
				}
			}
		}
	}

	for (int i=1; i<=n; i++) {
		cout << sol[i] << ' ';
	}

	
}