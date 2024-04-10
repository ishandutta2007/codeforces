#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};

vector<int> g[600000];
pair<int, int> c[600000];
int p[600000];
vector<int> v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c + 1, c + 1 + n);
    bool f = 1;
    for (int i = 1; i <= n; i++) {
        v.clear();
        int u = c[i].second;
        p[u] = c[i].first;
        for (auto x : g[u]) {
            if (p[x]) v.push_back(p[x]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int j = 0;
        for (j = 0; j < v.size(); j++) {
            if (v[j] != j + 1) break;
        }
        j++;
        if (j != c[i].first) f = 0;
    }
    if (!f)
        cout << -1;
    else {
        for (int i = 1; i <= n; i++) cout << c[i].second << ' ';
    }
}