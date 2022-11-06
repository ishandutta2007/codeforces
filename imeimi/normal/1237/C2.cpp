#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

struct point {
    int x, y, z, i;
    void scan(int idx) {
        i = idx;
        cin >> x >> y >> z;
    }
    bool operator<(const point &p) const {
        if (x != p.x) return x < p.x;
        if (y != p.y) return y < p.y;
        return z < p.z;
    }
};
vector<point> solve3(vector<point> ps) {
    vector<point> re;
    for (int i = 0; i < (int)ps.size(); ++i) {
        int j = i;
        while (j + 1 < (int)ps.size() && ps[i].y == ps[j + 1].y) {
            ++j;
        }
        vector<point> arg;
        for (int k = i; k <= j; ++k) {
            arg.push_back(ps[k]);
        }
        //arg = solve4(arg);
        for (point p : arg) re.push_back(p);
        i = j;
    }
    while ((int)re.size() > 1) {
        int a = re.back().i;
        re.pop_back();
        int b = re.back().i;
        re.pop_back();
        printf("%d %d\n", a, b);
    }
    return re;
}
vector<point> solve2(vector<point> ps) {
    vector<point> re;
    for (int i = 0; i < (int)ps.size(); ++i) {
        int j = i;
        while (j + 1 < (int)ps.size() && ps[i].y == ps[j + 1].y) {
            ++j;
        }
        vector<point> arg;
        for (int k = i; k <= j; ++k) {
            arg.push_back(ps[k]);
        }
        arg = solve3(arg);
        for (point p : arg) re.push_back(p);
        i = j;
    }
    while ((int)re.size() > 1) {
        int a = re.back().i;
        re.pop_back();
        int b = re.back().i;
        re.pop_back();
        printf("%d %d\n", a, b);
    }
    return re;
}

vector<point> solve1(vector<point> ps) {
    vector<point> re;
    for (int i = 0; i < (int)ps.size(); ++i) {
        int j = i;
        while (j + 1 < (int)ps.size() && ps[i].x == ps[j + 1].x) {
            ++j;
        }
        vector<point> arg;
        for (int k = i; k <= j; ++k) {
            arg.push_back(ps[k]);
        }
        arg = solve2(arg);
        for (point p : arg) re.push_back(p);
        i = j;
    }
    while ((int)re.size() > 1) {
        int a = re.back().i;
        re.pop_back();
        int b = re.back().i;
        re.pop_back();
        printf("%d %d\n", a, b);
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int n;
    cin >> n;
    vector<point> ps;
    for (int i = 1; i <= n; ++i) {
        point p;
        p.scan(i);
        ps.push_back(p);
    }
    sort(ps.begin(), ps.end());
    solve1(ps);
    return 0;
}