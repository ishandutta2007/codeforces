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

#define MAXM 11
#define MAXN 110

int inf = 10'000;

string s;
string a[MAXM];
int m;
int n;

int memo[MAXN];
int usedstring[MAXN];
int topos[MAXN];
int dp(int ind) {
    if (ind == -1) return 0;

    if (memo[ind] != -1) return memo[ind];

    int out = inf;
    rep(i, 0, m) {
        if (sz(a[i]) > ind+1) {
            continue;
        }

        int sind = ind-sz(a[i])+1;
        bool ok = true;
        rep(j, 0, sz(a[i])) {
            if (a[i][j] != s[sind]) {
                ok = false;
                break;
            }
            sind++;
        }
        if (!ok) continue;

        rep(j, ind-sz(a[i]), ind) {
            if (1 + dp(j) < out) {
                out = 1 + dp(j);
                usedstring[ind] = i;
                topos[ind] = j;
            }
        }
    }
    return memo[ind] = out;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        n = sz(s);
        cin >> m;
        rep(i, 0, m) cin >> a[i];

        memset(memo, -1, sizeof memo);

        int out = dp(n-1);
        if (out >= inf) cout << -1 << '\n';
        else {
            cout << out << '\n';
            int pos = n-1;
            while (pos != -1) {
                cout << usedstring[pos]+1 << ' ' << pos-sz(a[usedstring[pos]])+2 << '\n';
                pos = topos[pos];
            }
        }

    }
}