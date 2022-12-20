#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 1;
const long long inf = 2e18;
long long l1[N], l2[N], sz[N], ans = 0;
vector <int> e[N];

long long f(long long x) {
    return (x * (x + 1)) / 2;
}

void dfs1(int u, int pr) {
    sz[u] = 1;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dfs1(e[u][i], u);
        sz[u] += sz[e[u][i]];
    }
}

void dfs(int u, int pr) {
    map <long long, long long> m, m1;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dfs(e[u][i], u);
        long long x = l1[e[u][i]];
        if (m[sz[e[u][i]]] < l1[e[u][i]])
            m[sz[e[u][i]]] = l1[e[u][i]];
        else if (m1[sz[e[u][i]]] < l1[e[u][i]])
                m1[sz[e[u][i]]] = l1[e[u][i]];

    }
    long long tn = f(sz[1] - 1);
    for (auto it1 = m.begin(); it1 != m.end(); ++it1) {
        if (m1.count((*it1).first)) {
            long long c = m1[(*it1).first];
            ans = max(ans, (*it1).second + c + (sz[1] - (*it1).first) * (*it1).first + (sz[1] - (*it1).first) * (*it1).first - (*it1).first * (*it1).first);
        }
        for (auto it2 = m.begin(); it2 != m.end(); ++it2)
        if (it1 != it2) {
            ans = max(ans, (*it1).second + (*it2).second + (sz[1] - (*it1).first) * (*it1).first + (sz[1] - (*it2).first) * (*it2).first - (*it1).first * (*it2).first);
        } else if (m.size() == 1)
            ans = max(ans, (*it1).second + (sz[1] - (*it1).first) * (*it1).first);
    }
    l1[u] = 0;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        long long x = l1[e[u][i]] + (sz[u] - sz[e[u][i]]) * sz[e[u][i]];
        if (l1[u] < x)
            l1[u] = x;
    }
}

int main() {
    int i, j, k, n, t, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs1(1, 0);
    dfs(1, 0);
    cout << f(n - 1) + ans;
}