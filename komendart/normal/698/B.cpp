#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];
char color[maxn];
char cycle[maxn];

int dfs(int v) {
    if (color[v] == 1) return v;
    if (color[v] == 2) return -1;
    color[v] = 1;
    int t = dfs(a[v]);
    color[v] = 2;
    return t;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) {
            root = i;
        } else if (!color[i]) {
            int t = dfs(i);
            if (t != -1) cycle[t] = true;
        }
    }

    int ans = 0;
    if (root == -1) {
        ans++;
        for (int i = 1; i <= n; i++) {
            if (cycle[i]) {
                root = i;
                a[i] = i;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i != root && (a[i] == i || cycle[i])) {
            a[i] = root;
            ans++;
        }
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';


}