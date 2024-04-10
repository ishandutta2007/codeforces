#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 55;
const int sigma = 26;
const int inf = 1e9;

vector<pii> to[sigma];

string s[2];
bool valid[2][sigma][nmax][nmax];
bool good[nmax][nmax][nmax][nmax];

void solve() {
	for (int id = 0; id < 2; ++id) {
		for (int i = 0; i < sz(s[id]); ++i) {
			valid[id][s[id][i] - 'a'][i][i] = true;
		}
		for (int len = 2; len <= sz(s[id]); ++len) {
			for (int i = 0; i + len - 1 < sz(s[id]); ++i) {
				int j = i + len - 1;
				for (int c = 0; c < sigma; ++c) {
					for (pii p : to[c]) {
						for (int k = i; k < j; ++k) {
							if (valid[id][p.first][i][k] && valid[id][p.second][k + 1][j]) {
								valid[id][c][i][j] = true;
								break;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < sz(s[0]); ++i) {
		for (int j = i; j < sz(s[0]); ++j) {
			for (int c = 0; c < sigma; ++c) {
				if (!valid[0][c][i][j]) {
					continue;
				}
				for (int a = 0; a < sz(s[1]); ++a) {
					for (int b = a; b < sz(s[1]); ++b) {
						if (!valid[1][c][a][b]) {
							continue;
						}
						good[i][j][a][b] = true;
					}
				}
			}
		}
	}
}

int dp[nmax][nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s[0] >> s[1];

    int k;
    cin >> k;

    while (k--) {
    	char c;
    	cin >> c;
    	int x = c - 'a';
    	cin >> c >> c;
    	char a, b;
    	cin >> a >> b;
    	to[x].pb({a - 'a', b - 'a'});
    }

    solve();
    for (int i = 0; i < nmax; ++i) {
    	for (int j = 0; j < nmax; ++j) {
    		dp[i][j] = inf;
    	}
    }

    dp[0][0] = 0;
    for (int i = 0; i < sz(s[0]); ++i) {
    	for (int j = 0; j < sz(s[1]); ++j) {
    		for (int x = 0; x <= i; ++x) {
    			for (int y = 0; y <= j; ++y) {
    				if (good[x][i][y][j]) {
    					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[x][y] + 1);
    				}
    			}
    		}
    	}
    }

    int ans = dp[sz(s[0])][sz(s[1])];
    cout << (ans == inf ? -1 : ans) << "\n";
    
}