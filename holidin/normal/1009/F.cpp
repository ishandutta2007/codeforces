#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
const long long mod = 998244353;

map <int, int> m[N];
vector <int> v[N], e[N];
int mx[N], top = 0, t[N], ans[N];

int uni(int a, int b) {
    if (v[a].size() < v[b].size())
        swap(a, b);
    for (int i = 0; i < v[b].size(); ++i) {
        ++m[a][v[b][i]];
        if (m[a][v[b][i]] > m[a][mx[a]] || (v[b][i] < mx[a] && m[a][v[b][i]] == m[a][mx[a]]))
            mx[a] = v[b][i];
        v[a].push_back(v[b][i]);
    }
    return a;
}

int get_ans(int u, int pr, int deep){
    ++top;
    ++m[top][deep];
    mx[top] = deep;
    t[u] = top;
    v[top].push_back(deep);
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        get_ans(e[u][i], u, deep + 1);
        t[u] = uni(t[u], t[e[u][i]]);
    }
    ans[u] = mx[t[u]] - deep;
}



int main() {
    long long i, j, n, q, top, l, r, k, a, b;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    get_ans(1, 1, 1);
    for (i = 1; i <= n; ++i)
        cout << ans[i] << "\n";
}