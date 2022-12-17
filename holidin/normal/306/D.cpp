#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 1;
const int inf = 1e9 + 1;
const int mod = 1e9 + 7;
const long double eps = 1e-3;
const long double PI = acos(-1);
mt19937 rnd(58);

struct vect {
    long double x, y;
    bool operator==(const vect &right);
};

bool vect:: operator==(const vect &b) {
    return (x == b.x && y == b.y);
}


double cf1, cf2;

vect ret(vect a, long double alpha) {
    vect b;
    b.x = (a.x * cf1 - a.y * cf2);
    b.y = (a.x * cf2 + a.y * cf1);
    return b;
}

double t = 1 / 999.0;

double random_double() {
     return (rnd() & (4096*2-1)) * t + 1;
}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool flag = 0;
vect f[N];

vector <pair<double, double> > gen(int n, vector <pair<double, double> > &v) {
    long double angle = PI - (n - 2) * PI / n;
    f[0] = {1, 0};
    cf1 = cos(angle);
    cf2 = sin(angle);
    v[0] = {0, 0};
    set <double> s;
    int pos = 0;
    if (flag)
    if (rand() % 30 == 0)
        pos = 0;
    else
        pos = n - rand() % min(2, n) - 1;
    for (int i = pos; i < n - 1; ++i) {
        double c = random_double();
        while (s.find(c) != s.end())
            c = random_double();
        v[i + 1] = {v[i].fi + f[i].x * c, v[i].se + f[i].y * c};
        s.insert(c);
        if (!flag)
            f[i + 1] = ret(f[i], angle);
    }
    flag = 1;
    double c = dist(v[0].fi, v[0].se, v[n - 1].fi, v[n - 1].se);
    v[n] = {v[n - 1].fi + f[n - 1].x * c, v[n - 1].se + f[n - 1].y * c};
    return v;
}


void solve() {
    int i, j, k, n, d1, d2;
    vect a;
    long double angle;
    cin >> n;
    double mnn = 1e9;
    int cnt = 0;
    vector <pair<double, double> > v(n + 1);
    while (n > 4) {
        v = gen(n, v);
        mnn = min(mnn, abs((v[0].fi - (v.back()).fi)) + abs(v[0].se  - v.back().se));
        //cout << mnn << endl;
        ++cnt;
        if (abs((v[0].fi - (v.back()).fi)) + abs(v[0].se  - v.back().se) < eps / 2) {
            vector <double> vf;
            for (i = 1; i < v.size(); ++i)
                vf.push_back(sqrt((v[i - 1].fi - v[i].fi) * (v[i - 1].fi - v[i].fi) + (v[i - 1].se - v[i].se) * (v[i - 1].se - v[i].se)));
            sort(vf.begin(), vf.end());
            bool norm = 1;
            for (i = 1; i < vf.size(); ++i)
            if (abs(vf[i] - vf[i - 1]) < eps || vf[i - 1] < 1)
                norm = 0;
            if (norm) {
                for (i = 0; i < v.size() - 1; ++i)
                    cout << fixed << setprecision(12) << v[i].fi << ' ' << v[i].se << endl;
                return;
            }
        }
    }
    cout << "No solution" << endl;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}