#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};
Point operator-(const Point &lhs, const Point &rhs) {return Point(lhs.x - rhs.x, lhs.y - rhs.y);}
LL cross(const Point &lhs, const Point &rhs) {return 1LL * lhs.x * rhs.y - 1LL * lhs.y * rhs.x;}
LL dot(const Point &lhs, const Point &rhs) {return 1LL * lhs.x * rhs.x + 1LL * lhs.y * rhs.y;}
istream &operator>>(istream &lhs, Point &rhs) {return lhs >> rhs.x >> rhs.y;}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n;
    cin >> k >> n;
    vector<Point> a(k), b(n);
    for (int i = 0; i < k; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    vector<vector<vector<int>>> path(k);
    for (int i = 0; i < k; ++i) {
        path[i].resize(n);
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n && path[i][j].size() < k; ++l)
                if (cross(a[i] - b[l], b[j] - b[l]) == 0 && dot(a[i] - b[l], b[j] - b[l]) < 0)
                    path[i][j].push_back(l);
            sort(path[i][j].begin(), path[i][j].end(), [&](int x, int y) {return dot(b[j] - a[i], b[x] - a[i]) < dot(b[j] - a[i], b[y] - a[i]);});
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<bool> shot(n);
        ans += [&]() {
            vector<int> perm(k);
            iota(perm.begin(), perm.end(), 0);
            do {
                int tm = 0;
                vector<int> s;
                function<int(int)> dfs = [&](int x) {
                    if (tm == k)
                        return 0;
                    for (int y : path[perm[tm++]][x])
                        if (!shot[y] && !dfs(y))
                            return 0;
                    shot[x] = true;
                    s.push_back(x);
                    return 1;
                };
                int result = dfs(i);
                for (int x : s)
                    shot[x] = false;
                if (result == 1)
                    return 1;
            } while (next_permutation(perm.begin(), perm.end()));
            return 0;
        }();
    }
    cout << ans << endl;
    return 0;
}