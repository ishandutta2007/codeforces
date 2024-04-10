#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll mod = (1e8);

bool operator<(const vi& a, const vi& b)
{
    if (sz(a) != sz(b)) {
        return (sz(a) < sz(b));
    }
    for (int i = sz(a) - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            return (a[i] < b[i]);
        }
    }
    return false;
}

void convert(int x, vi& v)
{
    v.clear();
    v.pb(x);
    /*if (!x) {
        v.pb(0);
    }
    while (x) {
        v.pb(x % 10000);
        x /= 10000;
    }*/
}

vi operator+(vi a, vi b)
{
    while (sz(a) < sz(b)) {
        a.pb(0);
    }
    while (sz(b) < sz(a)) {
        b.pb(0);
    }
    vi ans;
    ll c = 0;
    for (int i = 0; i < sz(a); ++i) {
        c += a[i] + b[i];
        ans.pb(c % mod);
        c /= mod;
    }
    if (c) {
        ans.pb(c);
    }
    return ans;
}

vi operator*(vi a, int b)///for digits only
{
    vi ans;
    if (!b) {
        ans.pb(0);
        return ans;
    }
    if (sz(a) == 1 && !a[0]) {
        return a;
    }
    ll c = 0;
    for (int i = 0; i < sz(a); ++i) {
        c += a[i] * b;
        ans.pb(c % mod);
        c /= mod;
    }
    if (c) {
        ans.pb(c);
    }
    return ans;
}

vi operator*(vi a, vi b)
{
    if (sz(a) == 1 && !a[0]) {
        return a;
    }
    if (sz(b) == 1 && !b[0]) {
        return b;
    }
    vi ans;
    ans.pb(0);
    for (int i = 0; i < sz(b); ++i) {
        vi x = a * b[i];
        vi add;
        for (int j = 0; j < i; ++j) {
            add.pb(0);
        }
        for (int j = 0; j < sz(x); ++j) {
            add.pb(x[j]);
        }
        ans = ans + add;
    }
    return ans;
}

int sgn(int x)
{
    if (!x) {
        return 0;
    }
    return (x > 0 ? 1 : -1);
}

struct pt
{
    int x, y;
    int id;
    bool ccw(const pt& b)
    {
        return (x * b.y - y * b.x > 0);
    }
    bool operator<(const pt& other)
    {
        if (!y) {
            if (x > 0) {
                return true;
            }
            return (other.y < 0);
        }
        if (!other.y) {
            if (other.x > 0) {
                return false;
            }
            return (y >= 0);
        }
        if (sgn(y) != sgn(other.y)) {
            return sgn(y) == 1;
        }
        return ccw(other);
    }
};

int scal(const pt& a, const pt& b)
{
    return a.x * b.x + a.y * b.y;
}

int len(const pt& p)
{
    return scal(p, p);
}

bool better(const pt& p, const pt& q, const pt& a, const pt& b)
{
    if (sgn(scal(p, q)) <= 0 && sgn(scal(a, b)) == 1) {
        return false;
    }
    if (sgn(scal(p, q)) >= 0 && sgn(scal(a, b)) == -1) {
        return true;
    }
    vi l, r;
    convert(scal(p, q), l);
    convert(scal(a, b), r);
    vi u, v;
    convert(scal(p, q), u);
    convert(scal(a, b), v);
    l = l * u;
    r = r * v;
    convert(len(a), u);
    convert(len(p), v);
    l = l * u;
    r = r * v;
    convert(len(b), u);
    convert(len(q), v);
    l = l * u;
    r = r * v;
    if (sgn(scal(p, q)) > 0) {
        return (r < l);
    } else {
        return (l < r);
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    vector<pt> p;

    scanf("%d", &n);
    p.resize(n);
    forn(i, n) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].id = i + 1;
    }

    sort(all(p));

    int a = 0, b = 1;
    for (int i = 1; i < n; ++i) {
        if (better(p[i], p[(i + 1) % n], p[a], p[b])) {
            a = i;
            b = (i + 1) % n;
            //cout << "change\n";
        }
    }

    printf("%d %d\n", p[a].id, p[b].id);

}