#include<bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int n, k, cnt;
int a[MAXN];
bool bio[MAXN][MAXN][MAXN], ok[MAXN];

void dfs (int pos, int ost, int x) {
    if (bio[pos][ost][x]) return;
    bio[pos][ost][x] = 1;
    if (pos == n) {
        if (ost == 0) ok[x] = 1, cnt++;
        return;
    }
    dfs(pos + 1, ost, x);
    if (ost - a[pos] >= 0) {
        dfs(pos + 1, ost - a[pos], x);
        dfs(pos + 1, ost - a[pos], x + a[pos]);
    }
}

int main () {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    dfs(0, k, 0);
    cout << cnt << endl;
    for (int i=0; i<=k; i++) {
        if (ok[i]) cout << i << " ";
    }
    return 0;
}