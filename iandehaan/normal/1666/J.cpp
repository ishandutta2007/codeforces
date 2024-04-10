#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;

#define pb push_back
#define mp make_pair

#define MAXN 210

int n;
ll c[MAXN][MAXN];
ll pref[MAXN][MAXN];

ll memo[MAXN][MAXN];
ll dp(int x, int y) {
    if (y < x) return 0;
    if (memo[x][y] != -1) return memo[x][y];

    ll commcost = 0;
    for (int i = x; i <= y; i++) {
        commcost += pref[i][n-1];
        commcost -= pref[i][y]; // remove c[i][x] + ... + c[i][y];
        if (x != 0) commcost += pref[i][x-1];
    }

    ll out = dp(x+1, y);

    for (int i = x; i <= y; i++) {
        out = min(out, dp(x, i-1) + dp(i+1, y));
    }
    return memo[x][y] = out+commcost;
}

int out[MAXN];

void extractSolution(int x, int y, int par) {
    if (y < x) return;
    //cout << x << ' ' << y << ' ' << par << endl;
    ll goal = dp(x, y);
    ll commcost = 0;
    for (int i = x; i <= y; i++) {
        commcost += pref[i][n-1];
        commcost -= pref[i][y]; // remove c[i][x] + ... + c[i][y];
        if (x != 0) commcost += pref[i][x-1];
    }

    for (int i = x; i <= y; i++) {
        ll med = commcost + dp(x, i-1) + dp(i+1, y);
        if (med == goal) {
            out[i] = par;
            extractSolution(x, i-1, i);
            extractSolution(i+1, y, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof memo);

    cin >> n;
    rep(i, 0, n) rep(j, 0, n) cin >> c[i][j];

    rep(i, 0, n) {
        pref[i][0] = c[i][0];
        rep(j, 1, n) pref[i][j] = pref[i][j-1] + c[i][j];
    }

    dp(0, n-1);
    extractSolution(0, n-1, -1);
    rep(i, 0, n) cout << out[i]+1 << ' ';
    cout << endl;
}