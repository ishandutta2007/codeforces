#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

typedef pair<int64, int64> point;

point operator-(point a, point b) {
    return {a.first - b.first, a.second - b.second};
}
int64 operator%(point a, point b) {
    return a.first * b.second - a.second * b.first;
}

int64 operator*(point a, point b) {
    return a.first * b.first + a.second * b.second;
}
point operator+(point a, point b) {
    return {a.first + b.first, a.second + b.second};
}

double operator~(point a) { return hypot(a.first, a.second); }

bool angle_cmp(point a, point b) {
    if (a % b == 0) return a * a < b * b;
    return a % b > 0;
}

vector<point> convexHull(vector<point> a) {
    point base = *min_element(a.begin(), a.end());
    for (point& p : a) {
        p = p - base;
    }
    sort(a.begin(), a.end(), angle_cmp);
    vector<point> hull;
    for (point p : a) {
        while (hull.size() >= 2 &&
               (p - hull.end()[-2]) % (hull.end()[-1] - hull.end()[-2]) >= 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }
    return hull;
}

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());

vector<tuple<int64, int64, int64>> read(int n) {
    vector<point> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    p = convexHull(p);
    n = p.size();
    vector<tuple<int64, int64, int64>> ret;
    for (int i = 0; i < n; ++i) {
        point a = p[i], b = p[(i + 1) % n], c = p[(i + 2) % n];
        point x = b - a, y = c - b;
        ret.emplace_back(x * x, x * y, x % y);
    }
    return ret;
}

template <class T>
int match(vector<T> a, vector<T> sum) {
    int n = a.size();
    for (auto x : a) sum.push_back(x);
    for (auto x : a) sum.push_back(x);
    int m = sum.size();
    vector<int> z(m, 0);
    int l = 0, r = 0;
    for (int i = 1; i < m; ++i) {
        if (z[i - l] < r - i) {
            z[i] = z[i - l];
        } else {
            r = max(r, i);
            l = i;
            while (r < m && sum[r - i] == sum[r]) r++;
            z[i] = r - i;
        }
        if (i >= n && z[i] >= n) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int na, nb;
    cin >> na >> nb;
    auto a = read(na);
    auto b = read(nb);
    cout << (match(a, b) ? "YES" : "NO") << endl;
    return 0;
}