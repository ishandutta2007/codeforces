#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;

const ld eps = 1e-9;
const ld inf = 1e18;

bool lt(ld a, ld b)
{
    return b - a > eps;
}

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool leq(ld a, ld b)
{
    return lt(a, b) || eq(a, b);
}

bool gt(ld a, ld b)
{
    return a - b > eps;
}

bool geq(ld a, ld b)
{
    return gt(a, b) || eq(a, b);
}

struct pt
{
    ld x, y;
    char color;
    pt() {}
    pt(ld x, ld y, char c) : x(x), y(y), color(c) {}
    pt operator-(const pt& other) const
    {
        return {x - other.x, y - other.y, 'R'};
    }
    bool operator>(const pt& other) const
    {
        return gt(x, other.x) || (eq(x, other.x) && gt(y, other.y));
    }
};

ld cross(const pt& p, const pt& q)
{
    return p.x * q.y - p.y * q.x;
}

pt start;

bool comp(const pt& a, const pt& b)
{
    return gt(cross(a - start, b - start), 0);
}

int main()
{

    //ifstream cin("input.txt");

    int n, m;
    cin >> n >> m;
    vector<pt> red(n);
    for (int i = 0; i < n; ++i) {
        cin >> red[i].x >> red[i].y;
        red[i].color = 'R';
    }

    vector<pt> blue(m);
    for (int i = 0; i < m; ++i) {
        cin >> blue[i].x >> blue[i].y;
        blue[i].color = 'B';
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<pt> v;
        for (int j = 0; j < n; ++j) {
            if (red[j] > red[i]) {
                v.pb(red[j]);
            }
        }
        for (int j = 0; j < m; ++j) {
            if (blue[j] > red[i]) {
                v.pb(blue[j]);
            }
        }
        start = red[i];
        sort(all(v), comp);
        for (int j = 0; j < sz(v); ++j) {
            if (v[j].color != 'R') {
                continue;
            }
            pt border = {inf, inf, 'R'};
            for (int k = j + 1; k < sz(v); ++k) {
                if (v[k].color == 'B') {
                    if (eq(border.x, inf) && eq(border.y, inf)) {
                        border = v[k];
                    } else if (gt(cross(border - v[j], v[k] - v[j]), 0)) {
                        border = v[k];
                    }
                    continue;
                }
                if ((eq(border.x, inf) && eq(border.y, inf)) || gt(cross(border - v[j], v[k] - v[j]), 0)) {
                    ++ans;
                    //cout << red[i].x << " " << red[i].y << " " << v[j].x << " " << v[j].y << " " << v[k].x << " " << v[k].y << "\n";
                }
            }
        }
    }

    cout << ans << "\n";

}