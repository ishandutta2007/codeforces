#include <bits/stdc++.h>
using namespace std;

struct Vec2 {
    int x, y;
    Vec2& operator+=(Vec2 const& o) {
        x += o.x;
        y += o.y;
        return *this;
    }
    Vec2 operator+(Vec2 const& o) {
        return Vec2(*this) += o;
    }
};

int n, m;
vector<vector<long long>> a;

vector<vector<map<long long, long long>>> dp;

long long f(int i, int j, long long height, int length) {
    if (i == 0 && j == 0) {
        return 0;
    }
    auto it = dp[i][j].find(height);
    if (it != dp[i][j].end())
        return it->second;

    long long res = std::numeric_limits<long long>::max();
    Vec2 pos{i, j};
    for (auto dir : {Vec2{-1, 0}, Vec2{0, -1}}) {
        Vec2 next = pos + dir;
        if (next.x >= 0 && next.y >= 0) {
            long long cur = 0;
            long long diff = height - a[next.x][next.y] - 1;
            if (diff >= 0) {
                // make suffix lower
                cur += length * diff;
                cur += f(next.x, next.y, a[next.x][next.y], length+1);
            } else {
                // make a[i-1][j] smaller
                cur -= diff;
                cur += f(next.x, next.y, height-1, length+1);
            }
            res = min(res, cur);
        }
    }
    dp[i][j][height] = res;
    return res;
}

void solve() {
    cin >> n >> m;
    a.assign(n, vector<long long>(m));
    for (auto& row : a) {
        for (auto& x : row)
            cin >> x;
    }

    dp.assign(n, vector<map<long long, long long>>(m));
    cout << f(n-1, m-1, a[n-1][m-1], 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        solve();
    }
}