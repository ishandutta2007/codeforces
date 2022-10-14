#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

int n, m, sol;
int a[MAXN][MAXN], p[MAXN][MAXN];
int cnt[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c;
            cin >> c;
            p[i][j] = a[i][j] = (c == '1');
            if (j > 0 && a[i][j]) p[i][j] += p[i][j-1];
        }
    }
    for (int c=0; c<m; c++) {
        memset(cnt, 0, sizeof cnt);
        for (int r=0; r<n; r++) {
            cnt[p[r][c]]++;
        }
        for (int i=m; i>0; i--) {
            cnt[i] += cnt[i+1];
            sol = max(sol, i * cnt[i]);
        }
    }
    cout << sol;
    return 0;
}