#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const ld eps = 1e-9;
const ld inf = 1e9;

struct ball
{
    ld x, v, m;
};

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool lt(ld a, ld b)
{
    return b - a > eps;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n;
    ld t;
    cin >> n >> t;

    vector<ball> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].v >> v[i].m;
    }

    ld curr = 0;
    while (true) {
        ld minn = inf;
        vector<pii> c;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (eq(v[i].v, v[j].v)) {
                    continue;
                }
                ld dt = (v[j].x - v[i].x) / (v[i].v - v[j].v);
                if (lt(dt, 0) || eq(dt, 0)) {
                    continue;
                }
                if (lt(dt, minn)) {
                    minn = dt;
                    c = {mp(i, j)};
                } else if (eq(dt, minn)) {
                    c.pb(mp(i, j));
                }
            }
        }
        if (lt(t, curr + minn)) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            v[i].x += v[i].v * minn;
        }
        curr += minn;
        for (pii& p : c) {
            int i = p.first, j = p.second;
            ld v1 = ((v[i].m - v[j].m) * v[i].v + 2 * v[j].m * v[j].v) / (v[i].m + v[j].m);
            ld v2 = ((v[j].m - v[i].m) * v[j].v + 2 * v[i].m * v[i].v) / (v[i].m + v[j].m);
            v[i].v = v1;
            v[j].v = v2;
        }
        /*cout << minn << "\n" << v[0].v << " " << v[1].v << "\n";
        break;*/
    }

    for (int i = 0; i < n; ++i) {
        v[i].x += v[i].v * (t - curr);
    }

    cout << fixed;
    cout.precision(12);

    for (int i = 0; i < n; ++i) {
        cout << v[i].x << "\n";
    }

}