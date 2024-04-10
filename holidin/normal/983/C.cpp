#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 1;
const int inf = 1e9;

int dp[N][10][10][10][10], dp1[N][10][10][10][10];
int a[N], b1[N];
int b[4], y[4];

vector <pair<int, vector<int> > > v;

void sorty() {
    for (int i = 1; i < 3; ++i)
    for (int j = 2; j >= i; --j)
    if (y[j - 1] > y[j])
        swap(y[j - 1], y[j]);
}

void sortb() {
    for (int i = 1; i < 4; ++i)
    for (int j = 3; j >= i; --j)
    if (b[j - 1] > b[j])
        swap(b[j - 1], b[j]);
}

int main() {
    int i, j, n, i1, i2, i3 ,i4, j1;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a[i] >> b1[i];
    }
    a[0] = 1;
    for (i = 0; i <= n; ++i)
    for (i1 = 0; i1 <= 9; ++i1)
    for (i2 = 0; i2 <= 9; ++i2)
    for (i3 = 0; i3 <= 9; ++i3)
    for (i4 = 0; i4 <= 9; ++i4) {
        dp[i][i1][i2][i3][i4] = inf;
        dp1[i][i1][i2][i3][i4] = inf;
    }
    dp[0][0][0][0][0] = 0;
    int ans = 2 * n;
    for (i1 = 0; i1 <= 9; ++i1)
    for (i2 = 0; i2 <= 9; ++i2)
    for (i3 = 0; i3 <= 9; ++i3)
    for (i4 = 0; i4 <= 9; ++i4) {
        int cnt = 0;
        if (i1 > 0)
            ++cnt;
        if (i2 > 0)
            ++cnt;
        if (i3 > 0)
            ++cnt;
        if (i4 > 0)
            ++cnt;
        vector <int> p;
        p.push_back(i1);
        p.push_back(i2);
        p.push_back(i3);
        p.push_back(i4);
        v.push_back({-cnt, p});
        if (i1 > 0)
            --cnt;
        p.push_back(-1);
        v.push_back({-cnt, p});
    }
    sort(v.begin(), v.end());
    for (i = 0; i <= n; ++i)
    for (int u = 0; u < v.size(); ++u)
    if (v[u].second.size() == 4) {
            i1 = v[u].second[0];
            i2 = v[u].second[1];
            i3 = v[u].second[2];
            i4 = v[u].second[3];
            if (dp[i][i1][i2][i3][i4] == inf)
                continue;
            int csv = 0;
            b[0] = i1;
            b[1] = i2;
            b[2] = i3;
            b[3] = i4;
            for (j = 0; j < 4; ++j)
            if (b[j] == 0)
                ++csv;
            for (j = 1; j <= 9; ++j) {
                int ii = i + 1;
                for (j1 = 0; j1 < 4; ++j1) {
                    if (b[j1] == j)
                        b[j1] = 0;
                    if (ii <= n && b[j1] == 0 && a[ii] == j) {
                        b[j1] = b1[ii];
                        ++ii;
                    }
                }
                if (ii != i + 1) {
                    --ii;
                    sortb();
                    dp[ii][b[0]][b[1]][b[2]][b[3]] = min(dp[ii][b[0]][b[1]][b[2]][b[3]], dp[i][i1][i2][i3][i4] + abs(a[i] - j));
                } else {
                    y[0] = 0;
                    y[1] = 0;
                    y[2] = 0;
                    y[3] = 0;
                    int top = 0;
                    for (int j1 = 0; j1 < 4; ++j1)
                    if (b[j1] != 0) {
                        y[top] = b[j1];
                        ++top;
                    }
                    if (top != 4) {
                        sorty();
                        dp1[i][j][y[0]][y[1]][y[2]] = min(dp1[i][j][y[0]][y[1]][y[2]], dp[i][i1][i2][i3][i4] + abs(j - a[i]));
                    }
                }
                b[0] = i1;
                b[1] = i2;
                b[2] = i3;
                b[3] = i4;
        }
    } else {
            i1 = v[u].second[0];
            i2 = v[u].second[1];
            i3 = v[u].second[2];
            i4 = v[u].second[3];
            if (dp1[i][i1][i2][i3][i4] == inf)
                continue;
            int csv = 0;
            b[0] = i2;
            b[1] = i3;
            b[2] = i4;
            b[3] = 0;
            for (j = 0; j < 4; ++j)
            if (b[j] == 0)
                ++csv;
            for (j = 1; j <= 9; ++j) {
                int ii = i + 1;
                for (j1 = 0; j1 < 4; ++j1) {
                    if (b[j1] == j)
                        b[j1] = 0;
                    if (ii <= n && b[j1] == 0 && a[ii] == j) {
                        b[j1] = b1[ii];
                        ++ii;
                    }
                }
                if (ii != i + 1) {
                    --ii;
                    sortb();
                    dp[ii][b[0]][b[1]][b[2]][b[3]] = min(dp[ii][b[0]][b[1]][b[2]][b[3]], dp1[i][i1][i2][i3][i4] + abs(i1 - j));
                } else {
                    int y[4];
                    y[0] = 0;
                    y[1] = 0;
                    y[2] = 0;
                    y[3] = 0;
                    int top = 0;
                    for (int j1 = 0; j1 < 4; ++j1)
                    if (b[j1] != 0) {
                        y[top] = b[j1];
                        ++top;
                    }
                    sorty();
                    if (top != 4)
                        dp1[i][j][y[0]][y[1]][y[2]] = min(dp1[i][j][y[0]][y[1]][y[2]], dp1[i][i1][i2][i3][i4] + abs(i1 - j));
                }
                b[0] = i2;
                b[1] = i3;
                b[2] = i4;
                b[3] = 0;

        }
    }
    int ans1 = dp[n][0][0][0][0];
    for (i = 1; i <= 9; ++i)
        ans1 = min(ans1, dp1[n][i][0][0][0]);
    cout << ans + ans1;
}