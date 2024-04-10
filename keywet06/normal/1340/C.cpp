#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> vx(m);
    for (int i = 0; i < m; i++) {
        cin >> vx[i];
    }
    sort(vx.begin(), vx.end());
    assert(vx[0] == 0);
    assert(vx[m - 1] == n);
    int g, r;
    cin >> g >> r;
    vector<bool> vis(m * g);
    vis[0] = true;
    vector<int> islands;
    islands.reserve(m);
    islands.push_back(0);
    vector<int> q;
    q.reserve(m * g);
    int ans = -1;
    for (int T = 0; !islands.empty(); T++) {
        q.clear();
        for (int i : islands) {
            q.push_back(i * g);
        }
        islands.clear();
        for (int z = 0; z < int(q.size()); z++) {
            int cur = q[z], i = cur / g, t = cur % g;
            for (int j : {i - 1, i + 1}) {
                if (!(0 <= j && j < m)) continue;
                int nt = t + abs(vx[i] - vx[j]);
                if (nt > g) continue;
                if (j == m - 1) {
                    int cnd = T * (g + r) + nt;
                    if (ans == -1 || cnd < ans) ans = cnd;
                }
                if (nt == g) nt = 0;
                if (vis[j * g + nt]) continue;
                vis[j * g + nt] = true;
                nt ? q.push_back(j * g + nt) : islands.push_back(j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}