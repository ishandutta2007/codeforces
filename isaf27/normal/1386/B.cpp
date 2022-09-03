//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b)
{
    return a ? gcd(b % a, a) : b;
}

struct point
{
    ll x, y;

    point() : x(0), y(0) {}

    point(ll x, ll y) : x(x), y(y) {}

    int half() const
    {
        if (y > 0 || (y == 0 && x > 0))
            return 1;
        return 2;
    }

    friend __int128 operator^(const point& p1, const point& p2)
    {
        return (__int128)p1.x * (__int128)p2.y - (__int128)p2.x * (__int128)p1.y;
    }

    friend __int128 operator*(const point& p1, const point& p2)
    {
        return (__int128)p1.x * (__int128)p2.x + (__int128)p1.y * (__int128)p2.y;
    }
};

struct cmp
{
    bool operator()(const point& p1, const point& p2) const
    {
        int h1 = p1.half();
        int h2 = p2.half();
        if (h1 != h2)
            return h1 < h2;
        __int128 mul = p1 ^ p2;
        if (mul != 0)
            return mul > 0;
        return p1 * p1 < p2 * p2;
    }
};

struct solver2
{
    int cnt_good;
    map<pair<ll, ll>, int> cnt;

    solver2() = default;

    void add(point p)
    {
        ll x = p.x;
        ll y = p.y;
        if (y < 0 || (y == 0 && x < 0))
        {
            x = -x;
            y = -y;
        }
        cnt[make_pair(x, y)]++;
        if (cnt[make_pair(x, y)] == 2)
            cnt_good++;
    }

    void del(point p)
    {
        ll x = p.x;
        ll y = p.y;
        if (y < 0 || (y == 0 && x < 0))
        {
            x = -x;
            y = -y;
        }
        cnt[make_pair(x, y)]--;
        if (cnt[make_pair(x, y)] == 1)
            cnt_good--;
    }

    bool check()
    {
        return (cnt_good > 0);
    }
};

struct solver3
{
    set<point, cmp> q;

    solver3() = default;

    void add(point p)
    {
        q.insert(p);
    }

    void del(point p)
    {
        q.erase(p);
    }

    bool check()
    {
        if (q.size() == 1)
            return false;
        point p = *q.begin();
        p.x = -p.x;
        p.y = -p.y;
        auto it = q.lower_bound(p);
        if (it == q.end())
            it = q.begin();
        point s0 = *it;
        if (it == q.begin())
            it = q.end();
        it--;
        point s1 = *it;
        if ((s0 ^ s1) > 0)
            return false;
        return true;
    }
};

struct backend
{
    solver2 s2;
    solver3 s3;

    backend() = default;

    void add(point p)
    {
        s2.add(p);
        s3.add(p);
    }

    void del(point p)
    {
        s2.del(p);
        s3.del(p);
    }

    int solve()
    {
        if (s2.check())
            return 2;
        if (s3.check())
            return 3;
        return 0;
    }
};

struct helper
{
    int total;
    int cnt0;
    map<pair<ll, ll>, int> cur;
    backend b;

    helper() = default;

    void add(ll x, ll y)
    {
        total++;
        if (x == 0 && y == 0)
        {
            cnt0++;
            return;
        }
        ll g = gcd(abs(x), abs(y));
        x /= g;
        y /= g;
        cur[make_pair(x, y)]++;
        if (cur[make_pair(x, y)] == 1)
            b.add(point(x, y));
    }

    void del(ll x, ll y)
    {
        total--;
        if (x == 0 && y == 0)
        {
            cnt0--;
            return;
        }
        ll g = gcd(abs(x), abs(y));
        x /= g;
        y /= g;
        cur[make_pair(x, y)]--;
        if (cur[make_pair(x, y)] == 0)
            b.del(point(x, y));
    }

    int solve()
    {
        if (cnt0 > 0)
            return 1;
        if (total == 0)
            return 0;
        return b.solve();
    }
};

typedef tuple<ll, ll, ll> p3d;

int q;
p3d v0;
vector<p3d> v;

p3d read()
{
    ll x, y, z;
    cin >> x >> y >> z;
    return make_tuple(x, y, z);
}

helper h;

pair<ll, ll> getpoint(p3d p)
{
    ll z0 = get<0>(p) * get<1>(v0) - get<1>(p) * get<0>(v0);
    ll y0 = get<0>(p) * get<2>(v0) - get<2>(p) * get<0>(v0);
    ll x0 = get<1>(p) * get<2>(v0) - get<2>(p) * get<1>(v0);
    if (get<0>(v0) != 0)
        return make_pair(y0, z0);
    if (get<1>(v0) != 0)
        return make_pair(x0, z0);
    return make_pair(x0, y0);
}

void add(p3d p)
{
    pair<ll, ll> cur = getpoint(p);
    h.add(cur.first, cur.second);
}

void del(p3d p)
{
    pair<ll, ll> cur = getpoint(p);
    h.del(cur.first, cur.second);
}

int solve()
{
    return h.solve();
}

int main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    v0 = read();
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        char x;
        cin >> x;
        if (x == 'A')
        {
            v.push_back(read());
            add(v.back());
        }
        else
        {
            int id;
            cin >> id;
            del(v[id - 1]);
        }
        cout << solve() << "\n";
    }
    return 0;
}