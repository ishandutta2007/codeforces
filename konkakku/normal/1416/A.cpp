#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, t, a[N], pre[N];
bool chk[N];
vector<int> ve[N];

int solve(int u) {
    int l = 0, ans = 0;
    for (int v : ve[u]) {
        ans = max(ans, v - l - 1);
        l = v;
    }
    ans = max(ans, n - l);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    pre[0] = N;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ve[a[i]].push_back(i);
            pre[i] = N;
        }
        for (int i = 1; i <= n; i++) {
            if (!chk[a[i]]) {
                int tmp = solve(a[i]);
                pre[tmp + 1] = min(pre[tmp + 1], a[i]);
                chk[a[i]] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            chk[a[i]] = false;
            ve[a[i]].clear();
            pre[i] = min(pre[i], pre[i - 1]);
            cout << (pre[i] == N ? -1 : pre[i]) << " \n"[i == n];
        }
    }
}