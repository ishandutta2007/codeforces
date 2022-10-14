#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n, k;
vector <int> v[MAXN];

int dfs (int x, int rod) {
    if (x != 1 && v[x].size() == 1) return k;
    int mx = 0, br = 0;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        int val = dfs(sus, x);
        mx = max(mx, val);
        if (val <= 0) return -1;
        if (val == 1) br++;
    }
    if (br >= 2) return -1;
    if (br >= 1 && x != 1) return -1;
    return mx - 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
        }
        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            k = mid;
            if (dfs(1, 0) >= 0) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << lo << '\n';
    }
    return 0;
}