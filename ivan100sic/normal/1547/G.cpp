// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
vector<int> e[400005];

int t[400005];
int st[400005];

void dfs1(int x);
void dfs2(int x);
void dfs3(int x);

void dfs1(int x) {
    st[x]++;
    for (int y : e[x]) {
        if (st[y] && t[y] != -1) {
            t[y] = -1;
            dfs3(y);
        } else if (t[y] == 0) {
            t[y] = 1;
            dfs1(y);
        } else if (t[y] == 1) {
            t[y] = 2;
            dfs2(y);
        }
    }
    st[x]--;
}

void dfs2(int x) {
    st[x]++;
    for (int y : e[x]) {
        if (st[y] && t[y] != -1) {
            t[y] = -1;
            dfs3(y);
        } else if (t[y] == 0 || t[y] == 1) {
            t[y] = 2;
            dfs2(y);
        }
    }
    st[x]--;
}

void dfs3(int x) {
    st[x]++;
    for (int y : e[x]) {
        if (t[y] != -1) {
            t[y] = -1;
            dfs3(y);
        }
    }
    st[x]--;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            e[i] = {};
            t[i] = 0;
        }

        for (int i=0; i<m; i++) {
            int x, y;
            cin >> x >> y;
            e[x].push_back(y);
        }

        t[1] = 1;
        dfs1(1);
        for (int i=1; i<=n; i++) {
            cout << t[i] << " \n"[i == n];
        }
    }
}