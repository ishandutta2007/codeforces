#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

typedef int64 D;

struct P {
    D x, y;
    P(D x = 0, D y = 0) : x(x), y(y) {} 
    P operator+(P a) {
        return P(x + a.x, y + a.y);
    }
    P operator-(P a) {
        return P(x - a.x, y - a.y);
    }
    P operator*(D k) {
        return P(x * k, y * k);
    }
    D operator *(P a) {
        return x * a.y - y * a.x;
    }
    D operator ^(P a) {
        return x * a.x + y * a.y;
    }
    D len2() {
        return x * x + y * y;
    }
    P perp() {
        return P(y, -x);
    }
    bool operator==(P a) {
        return x == a.x && y == a.y;
    }
    void load() {
        int _x, _y;
        scanf("%d%d", &_x, &_y);
        x = _x, y = _y;
    }
    int getPl() {
        if (x < 0) return 1;
        if (x == 0 && y < 0) return 1;
        return 0;
    }
};

bool cmp(P p, P q) {
    int pl1 = p.getPl();
    int pl2 = q.getPl();
    if (pl1 != pl2) return pl1 < pl2;
    return p * q > 0;
}

bool inside(P p1, P p2, P p3, P q) {
    int64 s1 = (p2 - p1) * (p3 - p1);
    int64 s2 = abs((p1 - q) * (p2 - q)) + abs((p2 - q) * (p3 - q)) + abs((p3 - q) * (p1 - q));
    return abs(s1) == abs(s2);
}

P cv;

bool cmp0(P p, P q) {
    return cmp(p - cv, q - cv);
}

int main()
{
    vector<P> v;
    P c(0, 0);
    for (int it = 0; it < 3; ++it) {
        int n;
        cin >> n;
        vector<P> w(n);
        for (int i = 0; i < n; ++i)
            w[i].load();
        int ind = 0;
        for (int i = 0; i < n; ++i)
            if (mp(w[i].x, w[i].y) < mp(w[ind].x, w[ind].y))
                ind = i;
        rotate(w.begin(), w.begin() + ind, w.end());
        c = c + w[0];
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            v.pb(w[j] - w[i]);
        }
    }
    sort(all(v), cmp);
    vector<P> a;
    for (int i = 0; i < sz(v); ) {
        if (v[i].x == 0 && v[i].y == 0) {
            ++i;
            continue;
        }
        a.pb(c);
        int j = i;
        while (j < sz(v) && v[j] * v[i] == 0) {
            c = c + v[j];
            ++j;
        }       
        i = j;
    }
    int m;
    cin >> m;
    cv = a[0];
    for (int i = 0; i < m; ++i) {
        P p;
        p.load();
        p = p * 3LL;
        int ind = lower_bound(a.begin() + 1, a.end(), p, cmp0) - a.begin();
        ind %= sz(a);
        if (ind == 0) ++ind;
        int ind0 = (ind - 1 + sz(a)) % sz(a);
        while (ind0 == ind || ind0 == 0) ind0 = (ind0 + 1) % sz(a);
        bool res = inside(a[0], a[ind], a[ind0], p);
        printf("%s\n", res ? "YES" : "NO");
    }   
    return 0;
}