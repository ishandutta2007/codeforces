#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
const int N = 200000;
int deep[N];
vector <int> e[N];

void dfs(int u, int dp) {
    ++deep[dp];
    for (int i = 0; i < e[u].size(); ++i)
    dfs(e[u][i], dp + 1);
}
int main() {
    long long i, j, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 2; i <= n; ++i) {
        cin >> j;
        e[j].push_back(i);
    }
    dfs(1, 0);
    int ans = 0;
    for (i = 0; i < n; ++i)
        ans += deep[i] % 2;
    cout << ans;
}