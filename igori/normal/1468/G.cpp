#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

ll product(ll x1, ll y1, ll x2, ll y2)
{
    return x1 * y2 - x2 * y1;
}

struct Line{
    double a, b, c;
    Line(double x1, double y1, double x2, double y2)
    {
        a = y2 - y1;
        b = x1 - x2;
        c = - a * x1 - b * y1;
    }
};

pair<double, double> inter(Line L1, Line L2)
{
    double y = (L2.c * L1.a - L1.c * L2.a) / (L1.b * L2.a - L2.b * L1.a);
    double x = (L2.c * L1.b - L1.c * L2.b) / (L1.a * L2.b - L2.a * L1.b);
    return {x, y};
}

pair<double, double> intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    Line L1(x1, y1, x2, y2);
    Line L2(x3, y3, x4, y4);
    return inter(L1, L2);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    ll H;
    cin >> n >> H;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    ll X = x.back(), Y = y.back() + H;
    double ans = 0;
    ll Cx = x.back(), Cy = y.back();
    for (int i = n - 2; i >= 0; i--)
    {
        ll res = product(Cx - X, Cy - Y, x[i] - X, y[i] - Y);
        if (res <= 0)
        {
            if (Cx == x[i + 1])
            {
                ans += dist(x[i], y[i], x[i + 1], y[i + 1]);
                Cx = x[i], Cy = y[i];
                continue;
            }
            pair<double, double> pnt = intersect(X, Y, Cx, Cy, x[i], y[i], x[i + 1], y[i + 1]);
            ans += dist(x[i], y[i], pnt.first, pnt.second);
            Cx = x[i], Cy = y[i];
        }
    }
    cout << setprecision(20) << ans << "\n";
}