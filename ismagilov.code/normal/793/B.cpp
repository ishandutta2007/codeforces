#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd "\n"; return 0;
#define all(v) v.begin(), v.end()

using namespace std;

const int MAXN = 1e3 + 2;
const int INF = 1e10;
const int MOD = 1e9 + 7;

int ans[MAXN][MAXN][4];
int a[MAXN][MAXN];
vector<pr<int, int>> tt;
int n, m;

void bfs(int x, int y, int z, int kol) {
    if (kol >= 3){
        return;
    }
    if (x > 0 && x <= n && y > 0 && y <= m && !a[x][y]){
        ans[x][y][z] = kol;
        for (int i = 0; i < 4; i++){
            if (i != z){
                if (ans[x + tt[i].fs][y + tt[i].sc][i] > kol + 1){
                    bfs(x + tt[i].fs, y + tt[i].sc, i, kol + 1);
                }
            }
            else{
                if (ans[x + tt[i].fs][y + tt[i].sc][i] > kol){
                    bfs(x + tt[i].fs, y + tt[i].sc, i, kol);
                }
            }
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    tt.pb(mp(0, 1));
    tt.pb(mp(0, -1));
    tt.pb(mp(1, 0));
    tt.pb(mp(-1, 0));
    cin >> n >> m;
    pr<int, int> s;
    pr<int, int> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i + 1][j + 1] = 0;
            if (c == '*') {
                a[i + 1][j + 1] = 1;
            }
            if (c == 'S') {
                s = mp(i + 1, j + 1);
            }
            if (c == 'T') {
                t = mp(i + 1, j + 1);
            }
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            for (int k = 0; k < 4; k++) {
                ans[i][j][k] = 3;
            }
        }
    }
    bfs(s.fs, s.sc, 0, 0);
    bfs(s.fs, s.sc, 1, 0);
    bfs(s.fs, s.sc, 2, 0);
    bfs(s.fs, s.sc, 3, 0);
    if (ans[t.fs][t.sc][0] < 3 || ans[t.fs][t.sc][1] < 3 || ans[t.fs][t.sc][2] < 3 || ans[t.fs][t.sc][3] < 3){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}