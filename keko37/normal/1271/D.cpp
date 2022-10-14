#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 5005;

int n, m, k, sol;
int a[MAXN], b[MAXN], c[MAXN], mx[MAXN];
vector <int> v[MAXN];
multiset <int> ms;

bool cmp (int x, int y) {
    return c[x] > c[y];
}

bool update (int lim) {
    while (k < lim) {
        if (ms.empty()) {
            cout << -1;
            return 1;
        }
        ms.erase(ms.begin());
        k++;
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        mx[i + 1] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mx[b] = max(mx[b], a);
    }
    for (int i = 1; i <= n; i++) {
        v[mx[i]].push_back(i);
        if (update(a[i])) return 0;
        k += b[i];
        sort(v[i].begin(), v[i].end(), cmp);
        for (int j = 0; j < v[i].size(); j++) {
            ms.insert(c[v[i][j]]);
            k--;
        }
        if (update(0)) return 0;
    }
    for (auto x : ms) sol += x;
    cout << sol;
    return 0;
}