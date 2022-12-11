#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef pair<ld, ld> pll;

const ld eps = 1e-12;
const int ops = 300;
const ld inf = 1e18;

bool lt(ld a, ld b)
{
    return b - a > eps;
}

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool leq(ld a, ld b)
{
    return lt(a, b) || eq(a, b);
}

bool comp(pll& a, pll& b)
{
    return lt(b.first / b.second, a.first / a.second);
}

struct data
{
    ld a, p, q;
    bool operator<(const data& other) const
    {
        return lt(a, other.a);
    }
};

int main()
{

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second;
    }

    sort(all(v), comp);
    vector<data> d(n);
    vector<ld> sum(n);
    for (int i = 0; i < n; ++i) {
        if (i) {
            sum[i] = sum[i - 1];
        }
        sum[i] += v[i].second;
    }

    vector<int> group(n, -1);
    int g = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (v[i].first * v[i + 1].second == v[i + 1].first * v[i].second) {
            group[i] = group[i + 1] = g;
        } else {
            group[i] = g;
            group[i + 1] = g + 1;
            ++g;
        }
    }
    vector<int> finish(g + 1);
    for (int i = 0; i < n; ++i) {
        finish[group[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        d[i].a = v[i].first;
        ld x = 0;
        if (group[i]) {
            x = sum[finish[group[i] - 1]];
        }
        x += v[i].second;
        d[i].p = v[i].first * sum[finish[group[i]]];
        d[i].q = v[i].first * x;
    }

    sort(all(d));
    /*for (int i = 0; i < n; ++i) {
        cout << d[i].a << " " << d[i].p << " " << d[i].q << "\n";
    }*/

    ld lf = 0.0, rg = 1.0;

    for (int step = 0; step < ops; ++step) {
        ld c = (lf + rg) / 2;
        c /= sum[n - 1];
        ld maxim1 = -inf, maxim2 = -inf;
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (j && d[j].a != d[j - 1].a) {
               maxim1 = maxim2;
            }
            if (leq(d[j].a - c * d[j].p, maxim1)) {
                ok = false;
                break;
            }
            if (lt(maxim2, d[j].a - c * d[j].q)) {
                maxim2 = d[j].a - c * d[j].q;
            }
        }
        if (ok) {
            lf = c * sum[n - 1];
        } else {
            rg = c * sum[n - 1];
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << lf << "\n";

}