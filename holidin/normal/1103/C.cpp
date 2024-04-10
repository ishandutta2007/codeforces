#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;

vector <int> e[N], circ[N];
int v[N], deep[N], top = 0, n, k;
bool use[N];

bool dfs(int u, int pr) {
    if (deep[u] + 1 >= (n - 1) / k + 1) {
        cout << "PATH" << endl;
        cout << deep[u] + 1 << endl;
        cout << u << ' ';
        return true;
    }
    use[u] = true;
    for (int i = 0; i < e[u].size(); ++i)
    if (!use[e[u][i]]) {
        deep[e[u][i]] = deep[u] + 1;
        if (dfs(e[u][i], u)) {
            cout << u << ' ';
            return true;
        }
    }
    return false;
}

void find_circle(int u, int pr) {
    use[u] = true;
    bool lst = true;
    v[deep[u]] = u;
    int u1 = -1, u2 = -1;
    for (int i = 0; i < e[u].size(); ++i)
    if (deep[e[u][i]] == deep[u] + 1) {
        lst = false;
        find_circle(e[u][i], u);
    } else if (e[u][i] != pr)
            if (u1 < 0)
                u1 = e[u][i];
            else
                u2 = e[u][i];
    if (lst && top < k) {
        ++top;
        circ[top].push_back(u);
        if ((-deep[u1] + deep[u]) % 3 != 2) {
            for (int i = deep[u1]; i < deep[u]; ++i)
                circ[top].push_back(v[i]);
            if (circ[top].size() % 3 == 0)
                exit(1);
            return;
        }
        if ((-deep[u2] + deep[u]) % 3 != 2) {
            for (int i = deep[u2]; i < deep[u]; ++i)
                circ[top].push_back(v[i]);
            if (circ[top].size() % 3 == 0)
                exit(1);
            return;
        }
        for (int i = min(deep[u1], deep[u2]); i <= max(deep[u1], deep[u2]); ++i)
            circ[top].push_back(v[i]);
    }

}

int main() {
    int i, j, m, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (i = 0; i < m; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (i = 1; i <= n; ++i)
    if (dfs(i, 0))
        return 0;
    for (i = 1; i <= n; ++i)
        use[i] = false;
    for (i = 1; i <= n; ++i)
    if (!use[i])
        find_circle(i, 0);
    cout << "CYCLES\n";
    for (i = 1; i <= k; ++i) {
        if (circ[i].size() == 0)
                exit(1);
        cout << circ[i].size() << "\n";
        for (j = 0; j < circ[i].size(); ++j)
            cout << circ[i][j] << ' ';
        cout << "\n";
    }
}