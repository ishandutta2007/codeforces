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
typedef pair<int, int> pii;

const ld pi = 4 * atan(1.0);

struct matrix
{
    ld m[3][3];
    matrix()
    {
        m[0][0] = m[1][1] = m[2][2] = 1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i != j) {
                    m[i][j] = 0;
                }
            }
        }
    }
};

matrix E;

struct pt
{
    ld x, y;
};

ld dist(const pt& a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

matrix operator*(const matrix& a, const matrix& b)
{
    matrix c;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c.m[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                c.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return c;
}

const int nmax = 300500;

matrix t[4 * nmax];

pt calc(const matrix& m, int i)
{
    ld x = m.m[0][0] * (ld)(i) + m.m[0][2];
    ld y = m.m[1][0] * (ld)(i) + m.m[1][2];
    return {x, y};
}

void push(int v)
{
    t[v * 2] = t[v] * t[v * 2];
    t[v * 2 + 1] = t[v] * t[v * 2 + 1];
    t[v] = E;
}

pt get(int v, int tl, int tr, int pos)
{
    if (tl == tr) {
        return calc(t[v], pos + 1);
    }
    push(v);
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        return get(v * 2, tl, tm, pos);
    } else {
        return get(v * 2 + 1, tm + 1, tr, pos);
    }
}

void update(int v, int tl, int tr, int l, int r, const matrix& m)
{
    if (tl == l && tr == r) {
        t[v] = m * t[v];
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    if (r <= tm) {
        update(v * 2, tl, tm, l, r, m);
    } else if (l > tm) {
        update(v * 2 + 1, tm + 1, tr, l, r, m);
    } else {
        update(v * 2, tl, tm, l, tm, m);
        update(v * 2 + 1, tm + 1, tr, tm + 1, r, m);
    }
}

matrix movement(ld dx, ld dy)
{
    matrix m;
    m.m[0][2] = dx;
    m.m[1][2] = dy;
    return m;
}

matrix turn(ld a)
{
    matrix m;
    m.m[0][0] = cos(a), m.m[0][1] = sin(a);
    m.m[1][0] = -m.m[0][1], m.m[1][1] = m.m[0][0];
    return m;
}

void write(const matrix& m)
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << m.m[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    //freopen("input.txt", "r", stdin);

    int n, q;
    scanf("%d%d", &n, &q);

    while (q--) {
        int type, id, k;
        scanf("%d%d%d", &type, &id, &k);
        --id;
        if (type == 1) {
            pt p = get(1, 0, n - 1, id);
            pt start;
            if (id) {///BAD!!!
                start = get(1, 0, n - 1, id - 1);
            } else {
                start = {0, 0};
            }
            pt v;
            v.x = p.x - start.x, v.y = p.y - start.y;
            ld len = dist(v);
            v.x /= len, v.y /= len;
            v.x *= k, v.y *= k;
            update(1, 0, n - 1, id, n - 1, movement(v.x, v.y));
        } else {
            pt start;
            if (id) {
                start = get(1, 0, n - 1, id - 1);
            } else {
                start = {0, 0};
            }
            matrix m = movement(-start.x, -start.y);
            m = turn((ld)(k) * pi / 180.0) * m;
            m = movement(start.x, start.y) * m;
            update(1, 0, n - 1, id, n - 1, m);
        }
        pt p = get(1, 0, n - 1, n - 1);
        printf("%.10f %.10f\n", (double)(p.x), (double)(p.y));
    }

}