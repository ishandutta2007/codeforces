#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

const ll inf = (ll) (1e9) * (ll) (1e9);

struct pt
{
    ll x, y;
};

bool ccw(const pt& a, const pt& b)
{
    return a.x * b.y - a.y * b.x <= 0;
}

ll scal(const pt& a, const pt& b)
{
    return a.x * b.x + a.y * b.y;
}

bool cw(const pt& a, const pt& b, const pt& c)
{
    return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x) <= 0;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    ll s;

    scanf("%d%d%d%I64d", &n, &m, &k, &s);

    vector<ll> dollar(n);
    forn(i, n) {
        scanf("%I64d", &dollar[i]);
    }
    vector<ll> euro(n);
    forn(i, n) {
        scanf("%I64d", &euro[i]);
    }

    vector<pli> a, b;
    for (int i = 0; i < m; ++i) {
        int type;
        ll cost;
        scanf("%d%I64d", &type, &cost);
        if (type == 1) {
            a.pb(mp(cost, i + 1));
        } else {
            b.pb(mp(cost, i + 1));
        }
    }

    sort(all(a));
    sort(all(b));

    vector<pt> p;
    vector<pii> g;
    ll sumA = 0, sumB = 0;
    int posA, posB;
    if (sz(a) >= k) {
        for (int i = 0; i < k; ++i) {
            sumA += a[i].first;
        }
        posA = k - 1;
        posB = 0;
        p.pb({sumA, sumB});
        g.pb(mp(k, 0));
    } else {
        for (int i = 0; i < sz(a); ++i) {
            sumA += a[i].first;
        }
        posA = sz(a) - 1;
        for (int i = 0; i + sz(a) < k; ++i) {
            sumB += b[i].first;
        }
        posB = k - sz(a);
        p.pb({sumA, sumB});
        g.pb(mp(sz(a), k - sz(a)));
    }
    for (; posA >= 0; --posA) {
        sumA -= a[posA].first;
        if (posB == sz(b)) {
            break;
        }
        sumB += b[posB].first;
        ++posB;
        pt newP = {sumA, sumB};
        while (sz(p) >= 2 && cw(p[sz(p) - 2], p.back(), newP)) {
            p.pop_back();
            g.pop_back();
        }
        p.pb({sumA, sumB});
        g.pb(mp(posA, posB));
    }

    ll x = inf, y = inf;
    int dayX = -1, dayY = -1;
    for (int i = 0; i < n; ++i) {
        if (x > dollar[i]) {
            x = dollar[i];
            dayX = i + 1;
        }
        if (y > euro[i]) {
            y = euro[i];
            dayY = i + 1;
        }
        pt q = {x, y};
        int l = 0, r = sz(p) - 1;
        while (r - l >= 3) {
            int ll = (2 * l + r) / 3;
            int rr = (l + 2 * r) / 3;
            if (scal(p[ll], q) > scal(p[rr], q)) {
                l = ll;
            } else {
                r = rr;
            }
        }
        ll ans = inf;
        int day;
        for (int j = max(0, l - 3); j < min(sz(p), l + 4); ++j) {
        //for (int j = 0; j < sz(p); ++j) {
            if (ans > scal(q, p[j])) {
                ans = scal(q, p[j]);
                day = j;
            }
        }
        if (ans <= s) {
            printf("%d\n", i + 1);
            //printf("%I64d\n", ans);
            int cntA = g[day].first, cntB = g[day].second;
            for (int j = 0; j < cntA; ++j) {
                printf("%d %d\n", a[j].second, dayX);
            }
            for (int j = 0; j < cntB; ++j) {
                printf("%d %d\n", b[j].second, dayY);
            }
            return 0;
        }
    }

    printf("-1\n");

}