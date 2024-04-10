#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
const int inf = 1e9;

vector <int> v[MAXN + 1];
int t[MAXN];

int main() {
    int i, j, n;
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (i = 2; i < MAXN; ++i)
    if (v[i].size() == 0) {
        v[i].push_back(i);
        for (j = 2; i * j <= MAXN; ++j)
            v[i * j].push_back(i);
        t[i] = i;
    } else
        t[i] = i - v[i][v[i].size() - 1] + 1;
    cin >> n;
    int ans = inf;
    for (i = 1; i < v[n][v[n].size() - 1]; ++i)
        ans = min(ans, t[n - i]);
    cout << ans;
}