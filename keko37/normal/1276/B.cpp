#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

int t, n, m, a, b;
vector <int> v[MAXN];
int aa[MAXN], bb[MAXN];

void dfs_a (int x) {
    if (x == b || aa[x]) return;
    aa[x] = 1;
    for (auto sus : v[x]) dfs_a(sus);
}

void dfs_b (int x) {
    if (x == a || bb[x]) return;
    bb[x] = 1;
    for (auto sus : v[x]) dfs_b(sus);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> a >> b;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            aa[i] = bb[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs_a(a); dfs_b(b);
        int cnt_a = -1, cnt_b = -1;
        for (int i = 1; i <= n; i++) {
            if (aa[i] == 1 && bb[i] == 0) cnt_a++;
            if (aa[i] == 0 && bb[i] == 1) cnt_b++;
        }
        cout << (llint) cnt_a * cnt_b << endl;
    }
    return 0;
}