#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const int mod = 998244353;
const int N = 200000;
int dp[N + 1][8][8]; // state, need
string s;
vi a;
int n;

void add(int& val, int& val1) {
	val = (val + val1) % mod;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	string s;
	cin >> s;
	for(const auto& el : s) {
		a.push_back(el - '0');
	}
	n = s.size();
	for(int i = 0; i < 8; i++) {
		dp[n][0][i] = 1;
	}
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j < 8; j++) {
			for(int k = 0; k < 8; k++) {
				for(int here = 0; here < 8; here++) {
					bool ok = true;
					int nxt = 0;
					for(int num = 0; num < 3; num++) {
						if(((k >> num) & 1) && a[i] == 0 && ((here >> num) & 1)) {
							ok = false;
							break;
						}
						if(((k >> num) & 1) && a[i] == ((here >> num) & 1)) {
							nxt = nxt | (1 << num);
						}
					}
					if(!ok) continue;
					if(j == 0) {
						add(dp[i][j][k], dp[i + 1][j][nxt]);
						continue;
					}
					if(here == 7 || here == 0) {
						add(dp[i][j][k], dp[i + 1][j][nxt]);
						continue;
					}
					int fir = here & 1;
					int sec = (here & 2) >> 1;
					int thi = (here & 4) >> 2;
					int s1 = fir ^ sec;
					int s2 = fir ^ thi;
					int s3 = sec ^ thi;
					if(j == 1) {
						if(s1 + s2 < s3) continue;
						if(s1 + s2 > s3) {
							add(dp[i][j][k], dp[i + 1][0][nxt]);
						} else {
							add(dp[i][j][k], dp[i + 1][j][nxt]);
						}
					} else if(j == 2) {
						if(s1 + s3 < s2) continue;
						if(s1 + s3 > s2) {
							add(dp[i][j][k], dp[i + 1][0][nxt]);
						} else {
							add(dp[i][j][k], dp[i + 1][j][nxt]);
						}
					} else if(j == 3) {
						if(s3 + s2 < s1) continue;
						if(s3 + s2 > s1) {
							add(dp[i][j][k], dp[i + 1][0][nxt]);
						} else {
							add(dp[i][j][k], dp[i + 1][j][nxt]);
						}
					} else if(j == 4) {
						if(s1 + s3 < s2 || s3 + s2 < s1) continue;
						if(s1 + s3 > s2) {
							add(dp[i][j][k], dp[i + 1][3][nxt]);
						} else if(s3 + s2 > s1) {
							add(dp[i][j][k], dp[i + 1][2][nxt]);
						} else {
							add(dp[i][j][k], dp[i + 1][j][nxt]);
						}
					} else if(j == 5) {
						if(s1 + s2 < s3 || s3 + s2 < s1) continue;
						if(s1 + s2 > s3) {
							add(dp[i][j][k], dp[i + 1][3][nxt]);
						} else if(s3 + s2 > s1) {
							add(dp[i][j][k], dp[i + 1][1][nxt]);
						} else {
							add(dp[i][j][k], dp[i + 1][j][nxt]);
						}
					} else if(j == 6) {
						if(s1 + s2 < s3 || s1 + s3 < s2) continue;
						if(s1 + s2 > s3) {
							add(dp[i][j][k], dp[i + 1][2][nxt]);
						} else if(s1 + s3 > s2) {
							add(dp[i][j][k], dp[i + 1][1][nxt]);
						} else {
							add(dp[i][j][k], dp[i + 1][j][nxt]);
						}
					} else if(j == 7) {
						if(s1 + s2 < s3 || s1 + s3 < s2 || s3 + s2 < s1) continue;
						if(s1 + s2 > s3) {
							add(dp[i][j][k], dp[i + 1][4][nxt]);
						} else if(s1 + s3 > s2) {
							add(dp[i][j][k], dp[i + 1][5][nxt]);
						} else {
							add(dp[i][j][k], dp[i + 1][6][nxt]);
						}
					}
				}
			}
		}
	}
	cout << dp[0][7][7];
}