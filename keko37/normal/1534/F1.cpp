#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 400005;

int n, m, cnt;
int bio[MAXN], in[MAXN], boja[MAXN], deg[MAXN];
string s[MAXN];
vector <int> v[MAXN], r[MAXN], st;

void add_edge (int a, int b) {
    v[a].push_back(b);
    r[b].push_back(a);
}

void build () {
    for (int col = 0; col < m; col++) {
        for (int row = 0; row < n; row++) {
            if (s[row][col] == '.') continue;
            int curr = row * m + col;
            if (row != 0 && s[row - 1][col] == '#') add_edge(curr, (row - 1) * m + col);
            for (int i = row; i < n; i++) {
                if (i != row && s[i][col] == '#') {
                    add_edge(curr, i * m + col);
                    break;
                }
                if (col - 1 >= 0 && s[i][col - 1] == '#') add_edge(curr, i * m + (col - 1));
                if (col + 1 < m && s[i][col + 1] == '#') add_edge(curr, i * m + (col + 1));
            }
        }
    }
}

void dfs (int x) {
    bio[x] = 1;
    for (auto sus : v[x]) {
        if (!bio[sus]) dfs(sus);
    }
    st.push_back(x);
}

void dfs2 (int x) {
    bio[x] = 2;
    boja[x] = cnt;
    for (auto sus : r[x]) {
        if (bio[sus] != 2) dfs2(sus);
    }
}

void solve () {
    for (int i = 0; i < n * m; i++) {
        int row = i / m, col = i % m;
        if (s[row][col] == '.') continue;
        for (auto sus : v[i]) {
            if (boja[sus] != boja[i]) deg[boja[sus]]++;
        }
    }
    int sol = 0;
    for (int i = 1; i <= cnt; i++) {
        if (deg[i] == 0) sol++;
    }
    cout << sol;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) cin >> in[i];
    build();
    for (int i = 0; i < n * m; i++) {
        int row = i / m, col = i % m;
        if (s[row][col] == '.') continue;
        if (!bio[i]) dfs(i);
    }
    reverse(st.begin(), st.end());
    for (auto x : st) {
        if (bio[x] != 2) {
            cnt++;
            dfs2(x);
        }
    }
    solve();
    return 0;
}