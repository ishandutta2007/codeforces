#include <bits/stdc++.h>

using namespace std;

const int maxn = 31;
const int maxw = 305;

#define X first
#define Y second

pair<int, int> directions[8] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

int n;
int t[maxn];

int ans = 0;
char used[maxw][maxw][6][maxn][8];
char cells[maxw][maxw];

void rec(int x, int y, int rest, int k, int direction) {
    if (used[x][y][rest][k][direction]) return;
    used[x][y][rest][k][direction] = true;
    if (rest == 0) {
        if (k == n - 1) return;
        rec(x, y, t[k + 1], k + 1, (direction + 1) % 8);
        rec(x, y, t[k + 1], k + 1, (direction + 7) % 8);
        return;
    }
    x += directions[direction].X;
    y += directions[direction].Y;
    --rest;
    if (!cells[x][y]) ++ans;
    cells[x][y] = true;
    rec(x, y, rest, k, direction);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    rec(151, 151, t[0], 0, 0);
    cout << ans << '\n';
}