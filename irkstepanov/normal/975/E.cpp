#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct pt {
    ld x, y;
    pt() {}
    pt(ld x, ld y) : x(x), y(y) {}
    pt operator+(const pt& other) const {
        return {x + other.x, y + other.y};
    }
    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y};
    }
    pt operator*(ld k) const {
        return {x * k, y * k};
    }
};

ld cross(const pt& p, const pt& q) {
    return p.x * q.y - p.y * q.x;
}

ld dist(const pt& a, const pt& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

pt rot(const pt& p, ld a) {
    a = -a;
    ld s = sin(a), c = cos(a);
    return {c * p.x - s * p.y, s * p.x + c * p.y};
}

pt calc(ld a, pt center, pt initC, pt init, ld anglei, ld angle0) {
    ld d = a + anglei - angle0;
    pt ans = {0, 1};
    ans = rot(ans, d);
    ans = ans * dist(init, initC);
    //cout << d << "\n";
    ans = ans + center;
    //cout << center.x << " " << center.y << "\n";
    return ans;
}

ld dot(const pt& p, const pt& q) {
    return p.x * q.x + p.y * q.y;
}

pt f(vector<pt> p) {
    int n = sz(p);
    pt s = p[0];
    for (int i = 0; i < sz(p); ++i) {
        p[i] = p[i] - s;
    }
    pt center = {0, 0};
    ld area = 0;
    for (int i = 0; i < n; ++i) {
        area += cross(p[i], p[(i + 1) % n]);
    }
    area = abs(area) / 2;

    for (int i = 0; i < n; ++i) {
        pt u = p[i], v = p[(i + 1) % n];
        center.x += (u.x + v.x) * cross(u, v);
        center.y += (u.y + v.y) * cross(u, v);
    }

    center.x /= area * 6, center.y /= area * 6;
    return center + s;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    pt center = f(p);

    pt c = center;

    vector<ld> angle(n);
    for (int i = 0; i < n; ++i) {
        pt u = {0, 1};
        pt v = p[i] - center;
        angle[i] = atan2(cross(v, u), dot(v, u));
    }

    cout << fixed;
    cout.precision(20);

    //cout << center.x << " " << center.y << " " << angle[0] << "\n";

    int x = 0, y = 1;
    ld a = angle[0];
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 2) {
            int i;
            cin >> i;
            --i;
            pt ans = calc(a, center, c, p[i], angle[i], angle[0]);
            cout << ans.x << " " << ans.y << "\n";
        } else {
            int pr, nx;
            cin >> pr >> nx;
            --pr, --nx;
            if (pr == y) {
                swap(x, y);
            }
            pt t = calc(a, center, c, p[y], angle[y], angle[0]);
            //cout << "!" << t.x << " " << t.y << "\n";
            pt dir = {0, -1};
            center = t + dir * dist(p[y], c);
            a = angle[0] - angle[y];
            x = nx;
        }
    }


    //cout << center.x << " " << center.y << "\n";

}