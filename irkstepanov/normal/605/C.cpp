#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

ll inf = (ll) (1e6);

const ld eps = 0.000000000001;

bool lt(ld a, ld b)
{
    return b - a > eps;
}

bool leq(ld a, ld b)
{
    return lt(a, b) || abs(a - b) <= eps;
}

bool cw(const pii& x, const pii& y, const pii& z)
{
    return (ll) (x.first - y.first) * (ll) (z.second - y.second) - (ll) (z.first - y.first) * (ll) (x.second - y.second) <= 0;
}

ld P, Q;

ld solve2(ld a1, ld b1, ld a2, ld b2)
{
    swap(a1, a2);
    swap(b1, b2);
    ld betta = (P * b1 - Q * a1) / (a2 * b1 - a1 * b2);
    if (lt(P - a2 * betta, 0.0)) {
        return inf;
    }
    ld alpha = (P - a2 * betta) / a1;
    if (lt(betta, 0.0) || lt(alpha, 0.0)) {
        return inf;
    }
    if (leq(P, alpha * a1 + betta * a2) && leq(Q, alpha * b1 + betta * b2)) {
        //cout << alpha << " " << betta << "\n";
        return alpha + betta;
    } else {
        return inf;
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n >> P >> Q;

    map<int, int> m;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        m[a] = max(m[a], b);
    }

    vector<pii> p;
    p.pb(mp(0, 0));
    p.pb(mp(m.begin()->first, m.begin()->second));

    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        if (it == m.begin()) {
            continue;
        }
        while (sz(p) >= 2) {
            int s = sz(p);
            if (cw(p[s - 2], p[s - 1], mp(it->first, it->second))) {
                p.pop_back();
            } else {
                break;
            }
        }
        p.pb(mp(it->first, it->second));
    }

    double ans = inf;

    for (auto it : p) {
        //cout << it.first << " " << it.second << "\n";
        double relax = max(P / (ld) it.first, Q / (ld) it.second);
        ans = min(ans, relax);
    }

    for (int i = 0; i < sz(p) - 1; ++i) {
        auto it1 = p[i];
        auto it2 = p[i + 1];
        double relax = solve2(it1.first, it1.second, it2.first, it2.second);
        ans = min(ans, relax);
    }

    cout << fixed;
    cout.precision(8);
    cout << ans << "\n";

}