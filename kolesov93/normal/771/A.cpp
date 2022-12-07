#include <bits/stdc++.h>
using namespace std;

vector<int> used;
vector< vector<int> > g;

pair<int, int> dfs(int x) {
    used[x] = 1;
    pair<int, int> total = {1, 0};
    for (int y : g[x]) {
        if (!used[y]) {
            auto ve = dfs(y);
            total.first = total.first + ve.first;
            total.second = total.second + ve.second;
        }
        total.second += 1;
    }
    return total;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);


    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    used.resize(n + 1);

    for (int i = 1; i <= n; ++i) 
        if (!used[i]) {
            auto ve = dfs(i);
//            cerr << ve.first << " " << ve.second << endl;
            if ( ((long long)ve.first) * (ve.first - 1) != ((long long)ve.second)) {
                puts("NO");
                return 0;
            }
        }
    puts("YES");

    return 0;
}