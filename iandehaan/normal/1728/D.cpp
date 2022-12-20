#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

string s;
int n;
#define MAXN 2010
int memo[MAXN][MAXN];

int dp(int x, int y) {
	// s[x, y]
	if (y < x) return 0;
	if (memo[x][y] != -2) return memo[x][y];

	bool cantie = false;

	// four options:
	// Alice left, Bob left
	int ll = dp(x+2, y);
	// Alice left, Bob right
	int lr = dp(x+1, y-1);

	if (ll == 1 && lr == 1) {
		// no matter what bob does, alice wins taking left
		return memo[x][y] = 1;
	} else if (ll != -1 && lr != -1) {
		// (otherwise bob could force win)
		bool canwin = true;
		bool localtie = true;
		if (ll == 0) {
			if (s[x] > s[x+1]) {
				canwin = false;
				localtie = false;
			} else if (s[x] == s[x+1]) {
				canwin = false;
			}
		}
		if (lr == 0) {
			if (s[x] > s[y]) {
				canwin = false;
				localtie = false;
			} else if (s[x] == s[y]) {
				canwin = false;
			}
		}
		if (canwin) return memo[x][y] = 1;
		if (localtie) cantie = true;
	} 

	// Alice right, Bob left
	int rl = dp(x+1, y-1);
	int rr = dp(x, y-2);

	if (rl == 1 && rr == 1) {
		// no matter what bob does, alice wins taking right
		return memo[x][y] = 1;
	} else if (ll != -1 && lr != -1) {
		// (otherwise bob could force win)
		bool canwin = true;
		bool localtie = true;
		if (rl == 0) {
			if (s[y] > s[x]) {
				canwin = false;
				localtie = false;
			} else if (s[y] == s[x]) {
				canwin = false;
			}
		}
		if (rr == 0) {
			if (s[y] > s[y-1]) {
				canwin = false;
				localtie = false;
			} else if (s[y] == s[y-1]) {
				canwin = false;
			}
		}
		if (canwin) return memo[x][y] = 1;
		if (localtie) cantie = true;
	} 

	if (cantie) return memo[x][y] = 0;
	else return memo[x][y] = -1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		n = sz(s);
		rep(i, 0, n) rep(j, 0, n) memo[i][j] = -2;
		int res = dp(0, n-1);
		if (res == 1) cout << "Alice\n";
		else if (res == 0) cout << "Draw\n";
		else cout << "Bob\n";
	}
}