#include <bits/stdc++.h>
using namespace std;

bool use[4][4], p[4];
vector <int> e[4][4];
long long sum, ans;
int st[4];

int dfs(int u) {
    int cnt = st[u] % 2 == 1;
    p[u] = true;
    for (int i = 0; i < 4; ++i)
    if ((e[min(u, i)][max(u, i)].size() > use[min(u, i)][max(u, i)]) && !p[i])
        cnt += dfs(i);
    return cnt;
}

void rec(int u) {
    if (u == 16) {
        int cnt = 0;
        for (int i = 0; i < 4; ++i)
        if (st[i] % 2 == 1)
            ++cnt;
        for (int i = 0; i < 4; ++i) {
            long long ans1 = 0;
            for (int j = 0; j < 4; ++j)
                p[j] = false;
            int x = dfs(i);
            if (x <= 2)
                for (int i1 = 0; i1 < 4; ++i1)
                for (int j1 = 0; j1 < 4; ++j1)
                if (p[i1] && p[j1])
                    for (int j = use[i1][j1]; j < e[i1][j1].size(); ++j)
                        ans1 += e[i1][j1][j];
            ans = max(ans, ans1);
        }
    } else {
        rec(u + 1);
        if (e[u / 4][u % 4].size() != 0) {
            use[u / 4][u % 4] = true;
            --st[u / 4];
            --st[u % 4];
            rec(u + 1);
            use[u / 4][u % 4] = false;
            ++st[u / 4];
            ++st[u % 4];
        }
    }
}

int main() {
    int i, j, n, a, b, c;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    ans = 0, sum = 0;
    for (i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        if (a > c)
            swap(a, c);
        --a;
        --c;
        e[a][c].push_back(b);
        sum += b;
        ++st[a];
        ++st[c];
    }
    for (i = 0; i < 4; ++i)
    for (j = 0; j < 4; ++j)
        sort(e[i][j].begin(), e[i][j].end());
    rec(0);
    cout << ans;
}