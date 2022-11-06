#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5 + 5;

int n, m, k;

map<int, vector< pair<int, int> > > d1;
map<int, vector< pair<int, int> > > d2;
int ans[maxn];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        d1[x + y].push_back({i, x});
        d2[x - y].push_back({i, x});
    }

    for (int i = 0; i < k; i++) {
        ans[i] = -1;
    }

    int curx = 0, cury = 0;
    int dx = 1, dy = 1;
    for (int q = 0;;) {
        if (dx + dy == 0) {
            for (auto i: d1[curx + cury]) {
                if (ans[i.first] == -1) {
                    ans[i.first] = q + abs(curx - i.second);
                }
            }
        } else {
            for (auto i: d2[curx - cury]) {
                if (ans[i.first] == -1) {
                    ans[i.first] = q + abs(curx - i.second);
                }
            }
        }
        int t = n + m;
        if (dx > 0) t = min(t, n - curx);
        else t = min(t, curx);
        if (dy > 0) t = min(t, m - cury);
        else t = min(t, cury);
        curx += t * dx;
        cury += t * dy;
        if (curx == n || curx == 0) {
            if (cury == m || cury == 0) break;
            dx = -dx;
        }
        if (cury == m || cury == 0) dy = -dy;
        q += t;
    }

    for (int i = 0; i < k; i++) {
        cout << ans[i] << '\n';
    }
}