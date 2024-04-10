#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, N;
string s;

int substring_transitions[55][55][2];
int prefix_transitions[55][2];

// 1 - number of letters added
// 2 - length of longest prefix match
// 3 - start of best infix
// 4 - length of best infix
// (longest infix of s which is a prefix of X)
ll dp[55][55][55][55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> N >> s;
	n = s.size();
	s = string(" ") + s;

	// calc substring transitions
	for (int i=1; i<=n; i++) {
		for (int l=0; i+l-1<=n; l++) {
			for (int y=0; y<=1; y++) {
				string p = s.substr(i, l) + (char)(y + 48);
				auto j = s.find(p);
				if (j == string::npos) {
					substring_transitions[i][l][y] = -1;					
				} else {
					substring_transitions[i][l][y] = j;					
				}
			}
		}
	}

	// calc prefix transitions
	for (int i=0; i<=n; i++) {
		for (int y=0; y<=1; y++) {
			string p = s.substr(1, i) + (char)(y + 48);
			prefix_transitions[i][y] = 0;
			for (int j=i+1; j>=1; j--)
				if (s.substr(1, j) == p.substr(i+1 - j)) {
					prefix_transitions[i][y] = j;
					break;
				}
		}
	}

	// dp
	dp[0][0][1][0] = 1;

	for (int i=0; i<N; i++) { // number of letters added
		for (int j=0; j<=n; j++) { // length of longest prefix match
			for (int k=1; k<=n; k++) { // start of best infix
				for (int l=0; l<=n; l++) { // length of best infix
					for (int y=0; y<2; y++) {

						int jj = prefix_transitions[j][y];
						if (j == n)
							jj = n;
						int kk = -1, ll = -1;

						if (l == i) { // extension possible
							int st = substring_transitions[k][l][y];
							if (st == -1) {
								kk = k;
								ll = l;
							} else {
								kk = st;
								ll = l + 1;
							}	
						} else { // extension not possible :(
							kk = k;
							ll = l;
						}

						dp[i+1][jj][kk][ll] += dp[i][j][k][l];
					}
				}
			}
		}
	}

	ll sol = 0;

	string ss = s.substr(1);

	for (int j=0; j<=n; j++) { // length of longest prefix match
		for (int k=1; k<=n; k++) { // start of best infix
			for (int l=0; l<=n; l++) { // length of best infix
				string p = s.substr(1, j);
				p += s.substr(k, l);

				if (p.find(ss) != string::npos)
					sol += dp[N][j][k][l];
			}
		}
	}

	cout << sol << '\n';
}