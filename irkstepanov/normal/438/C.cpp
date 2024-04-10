#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

const ll mod = 1e9 + 7;
const ld eps = 0.00000001;
const ld pi = 4 * atan(1.0);

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mult(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

struct pt
{
    ld x, y;
};

struct line
{
    ld a, b, c;
};

ld dist(const pt& a, const pt& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

line buildLine(const pt& p, const pt& q)
{
    line l;
    l.a = p.y - q.y;
    l.b = q.x - p.x;
    l.c = p.x * q.y - q.x * p.y;
    return l;
}

pt intersectLines(const line& l, const line& m)
{
    ld a1 = l.a, b1 = l.b, c1 = l.c;
    ld a2 = m.a, b2 = m.b, c2 = m.c;
    ld det = a1 * b2 - a2 * b1;
    ld det1 = (-c1) * b2 - (-c2) * b1;
    ld det2 = a1 * (-c2) - a2 * (-c1);
    pt p = {det1 / det, det2 / det};
    return p;
}

bool onSegment(const pt& p, const pt& a, const pt& b)
{
    return eq(dist(a, b), dist(a, p) + dist(p, b));
}

bool collinear(const line& l, const line& m)
{
    ld a1 = l.a, b1 = l.b;
    ld a2 = m.a, b2 = m.b;
    return eq(a1 * b2, a2 * b1);
}

vector<pt> p;
int n;

ld angle(const pt& a, const pt& b)
{
    ld xx = a.x * b.y - a.y * b.x;
    ld yy = a.x * b.x + a.y * b.y;
    return atan2(xx, yy);
}

bool within(const pt& t)
{
    ld c = 0.0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        pt q, r;
        q.x = p[i].x - t.x, q.y = p[i].y - t.y;
        r.x = p[j].x - t.x, r.y = p[j].y - t.y;
        c += angle(q, r);
    }
    return eq(abs(c), 2 * pi);
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    vector<vector<char> > ok(n, vector<char>(n, true));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i || j == (i + n - 1) % n || j == (i + 1) % n) {
                continue;
            }
            pt &a = p[i], &b = p[j];
            line l = buildLine(a, b);
            for (int u = 0; u < n; ++u) {
                int v = (u + 1) % n;
                line m = buildLine(p[u], p[v]);
                if (collinear(l, m)) {
                    if (u != i && u != j && onSegment(p[u], a, b)) {
                        ok[i][j] = false;
                        break;
                    } else if (v != i && v != j && onSegment(p[v], a, b)) {
                        ok[i][j] = false;
                        break;
                    } else {
                        continue;
                    }
                } else {
                    if (u == i || u == j || v == i || v == j) {
                        continue;
                    }
                    pt t = intersectLines(l, m);
                    if (onSegment(t, a, b) && onSegment(t, p[u], p[v])) {
                        ok[i][j] = false;
                        break;
                    }
                }
            }
            pt t;
            t.x = (a.x + b.x) / 2.0, t.y = (a.y + b.y) / 2.0;
            if (within(t)) {
                continue;
            } else {
                ok[i][j] = false;
            }
        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!ok[i][j]) {
                cout << i << " " << j << "\n";
            }
        }
    }*/

    vector<vector<ll> > dp(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        dp[i][(i + 1) % n] = 1;
    }

    for (int s = 2; s < n; ++s) {
        for (int i = 0; i < n; ++i) {
            int j = (i + s) % n;
            for (int k = (i + 1) % n; k != j; k = (k + 1) % n) {
                if (ok[i][k] && ok[k][j]) {
                    ll t = dp[i][k];
                    mult(t, dp[k][j]);
                    add(dp[i][j], t);
                }
            }
        }
    }

    cout << dp[0][n - 1] << "\n";

}