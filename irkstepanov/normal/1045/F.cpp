#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Point {
    int x, y, id;
};

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y, 0};
}

bool operator<(const Point &a, const Point &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

ll cross(const Point &a, const Point &b) {
    return (ll)a.x * b.y - (ll)a.y * b.x;
}

ll len(const Point &a) {
    return (ll)a.x * a.x + (ll)a.y * a.y;
}

const int MAXN = 2e5;
int del[MAXN];
int good[MAXN];

Point origin;

bool comp(const Point &a, const Point &b) {
    ll x =  cross(a - origin, b - origin);
    if (x != 0) {
        return x > 0;
    }
    return len(a) < len(b);
}


vector<int> convex(vector<Point> p) {
    sort(all(p));

    int n = sz(p);
    int k = -1;
    for (int i = 0; i < n; ++i) {
        if (del[p[i].id]) {
            continue;
        }
        k = i;
        break;
    }
    vector<int> st;
    origin = p[k];
    st.push_back(k);

    sort(p.begin() + k + 1, p.end(), comp);

    for (int i = k + 1; i < n; ++i) {
        if (del[p[i].id]) {
            continue;
        }

        while (sz(st) > 1 && cross(p[i] - p[st[sz(st) - 1]], p[i] - p[st[sz(st) - 2]]) >= 0) {
            st.pop_back();
        }

        st.push_back(i);
    }

    int l = -1, r = -1;
    for (int i = 0; i < sz(st); ++i) {
        if (del[p[st[i]].id]) {
            continue;
        }
        ll x;
        if (l == -1) {
            l = i;
        } else {
            x = cross(p[st[l]], p[st[i]]);
            if (x > 0 || (x == 0 && len(p[st[l]]) < len(p[st[i]]))) {
                l = i;
            }
        }

        if (r == -1) {
            r = i;
        } else {
            x = cross(p[st[r]], p[st[i]]);
            if (x < 0 || (x == 0 && len(p[st[r]]) < len(p[st[i]]))) {
                r = i;
            }
        }
    }

    // cout << "---" << endl;
    // for (int i = 0; i < sz(st); ++i) {
    //     cout << p[st[i]].x << " " << p[st[i]].y << endl;
    // }
    // cout << endl;

    // cout << l << " " << r << endl;
    for (int i = r; i != l; i = (i + 1) % sz(st)) {
        good[p[st[i]].id] = 1;
    }
    good[p[st[l]].id] = 1;

    

    vector<int> res;
    for (int el : st) {
        res.push_back(p[el].id);
    }

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    
    vector<int> c = convex(p);

    for (int i = 0; i < sz(c) - 1; i += 2) {
        del[c[i]] = 1;
    }
    convex(p);
    for (int i = 0; i < sz(c) - 1; i += 2) {
        del[c[i]] = 0;
    }

    for (int i = 1; i < sz(c) - 1; i += 2) {
        del[c[i]] = 1;
    }
    convex(p);
    for (int i = 1; i < sz(c) - 1; i += 2) {
        del[c[i]] = 0;
    }

    del[c.back()] = 1;
    convex(p);
    del[c.back()] = 0;

    for (int i = 0; i < sz(p); ++i) {
        if (good[p[i].id] && (p[i].x % 2 == 1 || p[i].y % 2 == 1)) {
            cout << "Ani" << endl;
            return 0;
        }
    }

    cout << "Borna" << endl;

}