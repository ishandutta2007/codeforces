#include <bits/stdc++.h>
using namespace std;
constexpr int L = 2E5;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    vector<pair<int, int>> e[2 * L];
    int d[2 * L];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        ++d[--x[i]];
        ++d[(--y[i]) += L];
        e[x[i]].emplace_back(y[i], i);
        e[y[i]].emplace_back(x[i], i);
    }
    set<int> s;
    int c[2 * L] = {};
    vector<int> color(n);
    for (int i = 0; i < 2 * L; ++i)
        if (d[i] % 2 == 1)
            s.insert(i);
    stack<int> rem;
    while (!s.empty()) {
        int u = *s.begin();
        s.erase(u);
        int v, i;
        do {
            assert(c[u] != e[u].size());
            tie(v, i) = e[u][c[u]++];
        } while (color[i] == -1);
        rem.push(i);
        color[i] = -1;
        --d[u];
        --d[v];
        if (d[v] % 2 == 1)
            s.insert(v);
        else
            s.erase(v);
    }
    vector<int> euler;
    function<void(int)> findEuler = [&](int u) {
        for (int &i = c[u]; i < e[u].size(); ++i){
            int v, j;
            tie(v, j) = e[u][i];
            if (color[j] == -1)
                continue;
            color[j] = -1;
            findEuler(v);
            euler.push_back(j);
        }
    };
    for (int i = 0; i < 2 * L; ++i)
        findEuler(i);
    for (int i = 0; i < euler.size(); ++i)
        color[euler[i]] = i % 2;
    memset(c, 0, sizeof(c));
    while (!rem.empty()) {
        int i = rem.top();
        rem.pop();
        if (c[x[i]] == -1 || c[y[i]] == -1) {
            color[i] = 0;
            ++c[x[i]];
            ++c[y[i]];
        } else {
            color[i] = 1;
            --c[x[i]];
            --c[y[i]];
        }
    }
    for (int i = 0; i < n; ++i)
        cout << "rb"[color[i]];
    cout << "\n";
    return 0;
}