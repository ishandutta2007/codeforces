#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100005;
int n, m, col[N];

vector<int> g[N];

int cnt[2];

bool dfs(int u) {
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (col[v] != -1) {
            if (col[u] == col[v]) return false;
            else continue;
        }
        col[v] = (col[u]^1);
        cnt[col[v]]++;
        if (!dfs(v)) return false;
    }
    return true;
}


vector<pair<int, int> > cc;

bool judge() {
    int flag = 0;
    memset(col, -1, sizeof(col));
    for (int i = 1; i <= n; i++) {
        if (col[i] != -1) continue;
        cnt[0] = cnt[1] = 0;
        col[i] = 0;
        cnt[0]++;
        if (!dfs(i)) return true;
        cc.push_back(make_pair(cnt[0], cnt[1]));
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (judge()) printf("0 1\n");
    else {
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (g[i].size() >= 2) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            long long ans = 0;
            for (int i = 0; i < cc.size(); i++) {
                ans += (long long)cc[i].first * (cc[i].first - 1) / 2;
                ans += (long long)cc[i].second * (cc[i].second - 1) / 2;
            }
            printf("1 %lld\n", ans);
        } else {
            if (m) {
                long long tmp = n - 2;
                printf("2 %lld\n", tmp * m);
            } else {
                printf("3 %lld\n", (long long)n * (n - 1) * (n - 2) / 6);
            }
        }
    }
    return 0;
}