#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int N = int(3e5) + 10;

int n;

int64 m = -int64(1e9) - 10, cnt;
int64 a[N];

vector<int> e[N];

int64 dfs(int i, int par) {
    int64 sum = a[i];
    for (int j : e[i]) {
        if (j == par) continue;
        sum += max(0LL, dfs(j, i));
    }
    m = max(m, sum);
    return sum;
}

int64 dfs2(int i, int par) {
    int64 sum = a[i];
    for (int j : e[i]) {
        if (j == par) continue;
        sum += max(0LL, dfs2(j, i));
    }
    if (sum == m) 
        ++cnt,
        sum = 0;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y, --x, --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(0, 0);
    dfs2(0, 0);
    cout << cnt * m << " " << cnt << "\n";
    return 0;
}