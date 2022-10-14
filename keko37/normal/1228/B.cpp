#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
const int MOD = 1000000007;

int n, m, moze = 1, sol = 1;
int a[MAXN][MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(a, -1, sizeof a);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        for (int j=0; j<x; j++) {
            a[i][j] = 1;
        }
        a[i][x] = 0;
    }
    for (int i=0; i<m; i++) {
        int x; cin >> x;
        for (int j=0; j<x; j++) {
            if (a[j][i] == 0) moze = 0;
            a[j][i] = 1;
        }
        if (a[x][i] == 1) moze = 0;
        a[x][i] = 0;
    }
    if (!moze) {
        cout << 0;
        return 0;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == -1) {
                sol = 2LL * sol % MOD;
            }
        }
    }
    cout << sol;
    return 0;
}