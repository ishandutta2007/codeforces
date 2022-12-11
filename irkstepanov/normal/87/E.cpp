#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

struct pt
{
    ll x, y;
    static ll cross(const pt& p, const pt& q)
    {
        return p.x * q.y - p.y * q.x;
    }
    int halfplane() const
    {
        return x > 0 || (x == 0 && y < 0);
    }
    bool operator<(const pt& other)
    {
        if (halfplane() != other.halfplane()) {
            return halfplane() > other.halfplane();
        }
        return cross(*this, other) > 0;
    }
};

pt operator+(const pt& p, const pt& q)
{
    return {p.x + q.x, p.y + q.y};
}

pt operator-(const pt& p, const pt& q)
{
    return {p.x - q.x, p.y - q.y};
}

void normalize(vector<pt>& p) //left top to p[0]
{
    int id = 0;
    for (int i = 1; i < sz(p); ++i) {
        if (p[i].x < p[id].x || (p[i].x == p[id].x && p[i].y > p[id].y)) {
            id = i;
        }
    }
    vector<pt> ans;
    for (int i = id; i < sz(p); ++i) {
        ans.pb(p[i]);
    }
    for (int i = 0; i < id; ++i) {
        ans.pb(p[i]);
    }
    p.swap(ans);
}

vector<pt> operator+(const vector<pt>& a, const vector<pt>& b)
{
    vector<pt> v;
    for (int i = 0; i < sz(a); ++i) {
        v.pb(a[(i + 1) % sz(a)] - a[i]);
    }
    for (int i = 0; i < sz(b); ++i) {
        v.pb(b[(i + 1) % sz(b)] - b[i]);
    }
    sort(all(v));
    vector<pt> ans;
    ans.pb(a[0] + b[0]);
    for (int i = 0; i < sz(v) - 1; ++i) {
        pt p = ans.back() + v[i];
        //cout << v[i].x << " " << v[i].y << "\n";
        if (i && v[i].x * v[i - 1].y == v[i].y * v[i - 1].x) {
            ans.pop_back();
        }
        ans.pb(p);
    }
    return ans;
}

ll area(const pt& a, const pt& b, const pt& c)
{
    pt x = b - a, y = c - a;
    return abs(pt::cross(x, y));
}

bool belong(const pt& p, const vector<pt>& v)
{
    int lf = 1, rg = sz(v) - 1;
    while (lf < rg - 1) {
        int md = (lf + rg) >> 1;
        pt v1 = v[md] - v[0], v2 = p - v[0];
        if (pt::cross(v1, v2) > 0) {
            lf = md;
        } else {
            rg = md;
        }
    }
    return area(v[0], v[lf], v[rg]) == area(v[0], p, v[lf]) + area(v[0], p, v[rg]) + area(v[lf], p, v[rg]);
}

int main()
{

    vector<pt> v;
    for (int i = 0; i < 3; ++i) {
        int n;
        cin >> n;
        vector<pt> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j].x >> a[j].y;
        }
        normalize(a);
        if (!i) {
            v.swap(a);
            continue;
        }
        vector<pt> ans = v + a;
        v.swap(ans);
    }

    int q;
    cin >> q;
    while (q--) {
        pt p;
        cin >> p.x >> p.y;
        p.x *= 3, p.y *= 3;
        if (belong(p, v)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}