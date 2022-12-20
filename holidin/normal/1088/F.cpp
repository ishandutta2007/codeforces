#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
const int LogN = 20;

unsigned long long a[N], d[N];
int t[N];
vector <int> e[N];

unsigned long long dfs(int u, int k) {
    d[k] = u;
    unsigned long long sum = 0;
    for (int i = 0; i < e[u].size(); ++i) {
        unsigned long long ans = 1e18;
        for (unsigned long long j = 0; j < LogN; ++j)
        if (k >= t[j])
            ans = min(ans, a[e[u][i]] + a[d[k - t[j] + 1]] +  j * a[d[k - t[j] + 1]]);
        else
            ans = min(ans, a[e[u][i]] + a[d[1]] +  j * a[d[1]]);
        sum += ans + dfs(e[u][i], k + 1);
    }
    return sum;
}

int main() {
    int i, j, k, n, a1, b1;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    int p = n;
    for (i = 1; i < n; ++i) {
        cin >> a1 >> b1;
        if (a[i] < a[p])
            p = i;
        if (a[a1] < a[b1])
            e[a1].push_back(b1);
        else
            e[b1].push_back(a1);
    }
    t[0] = 1;
    for (i = 1; i < LogN; ++i)
        t[i] = t[i - 1] * 2;
    cout << dfs(p, 1);
}