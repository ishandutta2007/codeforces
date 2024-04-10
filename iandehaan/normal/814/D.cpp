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

struct circ { 
    int x, y, r;

    long double getArea() {
        return 3.1415926536 * r * r;
    }

    int getLeft() {
        return x - r;
    }

    int getRight() {
        return x + r;
    }

    int getBot() {
        return y-r;
    }

    int getTop() {
        return y+r;
    }
};

#define MAXN 2000

int n;

circ a[MAXN];
int par[MAXN];
vector<int> children[MAXN];

long double memo[MAXN][2][2];
long double dp(int v, bool x, bool y) {
    if (memo[v][x][y] != -1) return memo[v][x][y];

    long double out = -(1e100);
    if (x) {
        long double local = a[v].getArea();
        for (int nxt : children[v]) {
            local += dp(nxt, false, y);
        }
        out = max(out, local);
    } else {
        long double local = -a[v].getArea();
        for (int nxt : children[v]) {
            local += dp(nxt, true, y);
        }
        out = max(out, local);
    }

    if (y) {
        long double local = a[v].getArea();
        for (int nxt : children[v]) {
            local += dp(nxt, x, false);
        }
        out = max(out, local);
    } else {
        long double local = -a[v].getArea();
        for (int nxt : children[v]) {
            local += dp(nxt, x, true);
        }
        out = max(out, local);
    }

    return memo[v][x][y] = out;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].r;
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) memo[i][j][k] = -1;

    for (int i = 0; i < n; i++) par[i] = -1;

    long double currarea[n];
    for (int i = 0; i < n; i++) currarea[i] = 0;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (i == j) continue;

        // is j a parent of i?
        if (a[i].getLeft() >= a[j].getLeft() && a[i].getRight() <= a[j].getRight() && a[i].getTop() <= a[j].getTop() && a[i].getBot() >= a[j].getBot()) {
            // yes!

            if (par[i] == -1 || a[j].getArea() < currarea[i]) {
                par[i] = j;
                currarea[i] = a[j].getArea();
            }
        }
    }

    for (int i = 0; i < n; i++) if (par[i] != -1) children[par[i]].pb(i);

    long double out = 0;
    for (int i = 0; i < n; i++) if (par[i] == -1) out += dp(i, true, true);
    cout << fixed << setprecision(10) << out << endl;
}