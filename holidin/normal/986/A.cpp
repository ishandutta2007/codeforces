#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

vector <int> e[N];
int a[N], d[N], s[N];
vector <int> v[N];

int main() {
    int i, j, n, m, k, s1, a1, b1;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> s1;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 0; i < m; ++i) {
        cin >> a1 >> b1;
        e[a1].push_back(b1);
        e[b1].push_back(a1);
    }
    for (i = 1; i <= k; ++i) {
        int top = 0, h = 1;
        for (j = 1; j <= n; ++j)
        if (a[j] == i) {
            ++top;
            s[top] = j;
            d[j] = 0;
        } else
            d[j] = 1e9;
        while (h <= top) {
            for (j = 0; j < e[s[h]].size(); ++j)
            if (d[e[s[h]][j]] > d[s[h]] + 1) {
                ++top;
                d[e[s[h]][j]] = d[s[h]] + 1;
                s[top] = e[s[h]][j];
            }
            ++h;
        }
        for (j = 1; j <= n; ++j)
            v[j].push_back(d[j]);
    }
    for (i = 1; i <= n; ++i) {
        sort(v[i].begin(), v[i].end());
        long long ans = 0;
        for (j = 0; j < s1; ++j)
            ans += v[i][j];
        cout << ans << ' ';
    }
}