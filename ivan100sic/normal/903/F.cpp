#include <bits/stdc++.h>
using namespace std;

int n;
int c[5];
char a[1005][5];

int dp[2][4][4][4][4];
int trans[5][5][5][5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> c[1] >> c[2] >> c[3] >> c[4];

	for (int i=1; i<=4; i++) {
		string s;
		cin >> s;
		for (int j=1; j<=n; j++) {
			a[j][i] = s[j-1];
		}
	}

	memset(trans, 63, sizeof(trans));

	// izracunaj prelaze

	for (int s1=0; s1<=4; s1++) {
		for (int s2=0; s2<=3; s2++) {
			for (int s3=0; s3<=2; s3++) {
				for (int s4=0; s4<=1; s4++) {
					int pom[5] = {0, 0, 0, 0, 0};

					for (int i=1; i<=s1; i++) {
						pom[i] = max(pom[i], s1);
					}
					for (int i=1; i<=s2; i++) {
						pom[i+1] = max(pom[i+1], s2);
					}
					for (int i=1; i<=s3; i++) {
						pom[i+2] = max(pom[i+2], s3);
					}
					for (int i=1; i<=s4; i++) {
						pom[i+3] = max(pom[i+3], s4);
					}

					int cena = c[s1] + c[s2] + c[s3] + c[s4];
					int& r = trans[pom[1]][pom[2]][pom[3]][pom[4]];
					r = min(r, cena);
				}
			}
		}
	}

	/*
	for (int f1=0; f1<=4; f1++) {
		for (int f2=0; f2<=4; f2++) {
			for (int f3=0; f3<=4; f3++) {
				for (int f4=0; f4<=4; f4++) {
					if (trans[f1][f2][f3][f4] < 123123123) {
						cerr << f1 << f2 << f3 << f4 << ' ';
						cerr << trans[f1][f2][f3][f4] << '\n';
					}
				}
			}
		}
	}
	*/

	memset(dp[0], 63, sizeof(dp[0]));
	dp[0][0][0][0][0] = 0;

	for (int i=0; i<n; i++) {
		// napredujem odavde
		auto curr = dp[i % 2];
		auto next = dp[1 - i % 2];

		memset(next, 63, sizeof(dp[0]));

		for (int f1=0; f1<4; f1++) {
			for (int f2=0; f2<4; f2++) {
				for (int f3=0; f3<4; f3++) {
					for (int f4=0; f4<4; f4++) {

						int crr = curr[f1][f2][f3][f4];

						if (crr >= 123123123) {
							continue;
						}

						// cerr << "consider " << f1 << f2 << f3 << f4 << '\n';

						for (int g1=0; g1<=4; g1++) {
							for (int g2=0; g2<=4; g2++) {
								for (int g3=0; g3<=4; g3++) {
									for (int g4=0; g4<=4; g4++) {

										int trr = trans[g1][g2][g3][g4];

										if (trr >= 123123123) {
											continue;
										}

										if (a[i+1][1] == '*' && f1 == 0 && g1 == 0) {
											continue;
										}
										if (a[i+1][2] == '*' && f2 == 0 && g2 == 0) {
											continue;
										}
										if (a[i+1][3] == '*' && f3 == 0 && g3 == 0) {
											continue;
										}
										if (a[i+1][4] == '*' && f4 == 0 && g4 == 0) {
											continue;
										}

										// izvrsi prelaz
										// cerr << "move " << f1 << f2 << f3 << f4 << '\n';

										int h1 = max(0, max(f1, g1) - 1);
										int h2 = max(0, max(f2, g2) - 1);
										int h3 = max(0, max(f3, g3) - 1);
										int h4 = max(0, max(f4, g4) - 1);

										int& ref = next[h1][h2][h3][h4];
										ref = min(ref, crr + trr);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	int sol = 123123123;

	for (int f1=0; f1<4; f1++) {
		for (int f2=0; f2<4; f2++) {
			for (int f3=0; f3<4; f3++) {
				for (int f4=0; f4<4; f4++) {
					sol = min(sol, dp[n%2][f1][f2][f3][f4]);
				}
			}
		}
	}

	cout << sol << '\n';

}