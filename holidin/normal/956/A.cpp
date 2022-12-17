#include <bits/stdc++.h>
using namespace std;
const int N = 201;

int t[N], cnt[N], cnt1[N], top;
string s[N];
vector <int> e[N];

void dfs(int u, int cvet) {
    t[u] = cvet;
    ++cnt[cvet];
    for (int i = 0; i < e[u].size(); ++i)
    if (t[e[u][i]] == 0)
         dfs(e[u][i], cvet);
}

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; ++i)
        cin >> s[i];
    for (i = 0; i < n; ++i)
    for (j = 0; j < k; ++j)
    if (s[i][j] == '#') {
        e[i].push_back(j + n);
        e[j + n].push_back(i);
    }
    for (i = 0; i < n + k; ++i)
    if (t[i] == 0) {
        ++top;
        dfs(i, top);
    }
    for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
    if (i != j)
        e[i].push_back(j);
    for (i = 0; i < k; ++i)
    for (j = 0; j < k; ++j)
    if (i != j)
        e[i + n].push_back(j + n);
    for (i = 0; i < n + k; ++i)
    for (j = 0; j < e[i].size(); ++j)
    if (t[i] == t[e[i][j]])
        ++cnt1[t[i]];
    bool can = true;
    for (i = 1; i <= top; ++i)
    if (cnt1[i] != cnt[i] * (cnt[i] - 1))
        can = false;
    if (can)
        cout << "Yes";
    else
        cout << "No";
}