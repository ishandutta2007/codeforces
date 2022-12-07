#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 111111;
struct Tp {
    int x, y;

    Tp() {}
    Tp(int x, int y) : x(x), y(y) {}

    bool operator<(const Tp& b) const {
        return y < b.y || y == b.y && x < b.x;
    }
} b[N];
vector<Tp> a;

ll mul(const Tp& a, const Tp& b, const Tp& c) {
    return (ll(c.x) - a.x) * (ll(b.y) - a.y) - (ll(c.y) - a.y) * (ll(b.x) - a.x);
}

bool toRight(const Tp& a, const Tp& b, const Tp& c) { 
    return (ll(c.x) - a.x) * (ll(b.y) - a.y) - (ll(c.y) - a.y) * (ll(b.x) - a.x) >= 0; // >= 0
}

bool inTri(const Tp& a, const Tp& b, const Tp& c, const Tp& p) { 
    ll A = b.y - c.y;
    ll B = c.x - b.x;
    ll C = - A * b.x - B * b.y;

    return A * p.x + B * p.y + C < 0;  // >0
}

bool checkIn(Tp& p, vector<Tp>& v) {
    int l = 2;
    int r = v.size() - 1;
    while (l < r) {
        int c = (l + r) / 2;
        if (toRight(v[0], v[c], p)) 
            r = c;
        else
            l = c + 1;
    }
    return inTri(v[0], v[l], v[l - 1], p);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);

    int x, y;
    scanf("%d%d", &x, &y);

    int fail = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &b[i].x, &b[i].y);
    }

    int maxx = 0, maxy = 0;
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > maxx) maxx = x;
        if (y > maxy) maxy = y;
        a.push_back(Tp(x, y));
        a.push_back(Tp(x, 0));
        a.push_back(Tp(0, y));
    }
    a.push_back(Tp(0, 0));

    for (int i = 0; i < n; ++i) {
        if (b[i].x >= maxx || b[i].y >= maxy) {
            fail = 1;
            break;
        }
    }

    if (fail) {
        puts("Max");
        return 0;
    }

    sort(a.begin(), a.end());
    vector<Tp> st1;
    vector<Tp> st2;
    for (int i = 0; i < a.size(); ++i) {
        while (st1.size() > 1 && mul(st1[st1.size() - 2], st1[st1.size() - 1], a[i]) >= 0) st1.pop_back();
        while (st2.size() > 1 && mul(st2[st2.size() - 2], st2[st2.size() - 1], a[i]) <= 0) st2.pop_back();
        st1.push_back(a[i]);
        st2.push_back(a[i]);
    }

    st2.pop_back();
    if (st2.size()) {
        st2.erase(st2.begin());
        reverse(st2.begin(), st2.end());
        st1.insert(st1.end(), st2.begin(), st2.end());
    }

    assert(toRight(Tp(0, 0), Tp(3, 10), Tp(10, 3)));
    assert(inTri(Tp(0, 0), Tp(3, 10), Tp(10, 3), Tp(2, 2)));

    for (int i = 0; i < n; ++i) {
        if (!checkIn(b[i], st1)) {
            puts("Max");
            return 0;
        }            
    }
    puts("Min");
        

//    for (int i = 0; i < st1.size(); ++i)
//        cerr << st1[i].x << " " << st1[i].y << endl;
    
    return 0;
}