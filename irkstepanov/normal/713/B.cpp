#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct pt
{
    int x, y;
    pt() {}
    pt(int x, int y) : x(x), y(y) {}
    pt operator+(const pt& other) const
    {
        return {x + other.x, y + other.y};
    }
    pt operator*(int k) const
    {
        return {x * k, y * k};
    }
    bool operator<(const pt& other) const
    {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
};

int n;

int get(const pt& a, const pt& b, const pt& shift, int val) // a, b -- corners; d -- shift
{
    int lf = 0, rg = n;
    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        pt c = a + shift * (md - 1);
        pt d = b + shift * (md - 1);
        pt minn = a;
        if (b < minn) {
            minn = b;
        }
        if (c < minn) {
            minn = c;
        }
        if (d < minn) {
            minn = d;
        }
        pt maxx = a;
        if (maxx < b) {
            maxx = b;
        }
        if (maxx < c) {
            maxx = c;
        }
        if (maxx < d) {
            maxx = d;
        }
        cout << "? " << minn.x << " " << minn.y << " " << maxx.x << " " << maxx.y << "\n";
        cout.flush();
        int res;
        cin >> res;
        if (res < val) {
            lf = md;
        } else {
            rg = md;
        }
    }
    return rg;
}

bool ok(int xl, int yl, int xr, int yr)
{
    if (xl > xr || yl > yr) {
        return false;
    }
    cout << "? " << xl << " " << yl << " " << xr << " " << yr << "\n";
    cout.flush();
    int res;
    cin >> res;
    if (res != 1) {
        return false;
    }
    if (yl < yr) {
        cout << "? " << xl << " " << yl + 1 << " " << xr << " " << yr << "\n";
        cout.flush();
        cin >> res;
        if (res != 0) {
            return false;
        }
        cout << "? " << xl << " " << yl << " " << xr << " " << yr - 1 << "\n";
        cout.flush();
        cin >> res;
        if (res != 0) {
            return false;
        }
    }
    if (xl < xr) {
        cout << "? " << xl + 1 << " " << yl << " " << xr << " " << yr << "\n";
        cout.flush();
        cin >> res;
        if (res != 0) {
            return false;
        }
        cout << "? " << xl << " " << yl << " " << xr - 1 << " " << yr << "\n";
        cout.flush();
        cin >> res;
        if (res != 0) {
            return false;
        }
    }
    return true;
}

int main()
{

    //ifstream cin("snakes.in");
    //ofstream cout("snakes.out");
    //ifstream cin("input.txt");
    //ofstream cout("homo.out");
    //freopen("input.txt", "r", stdin);
    //freopen("wa9.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> n;

    vector<pt> b;
    b.pb({1, 1});
    b.pb({1, n});
    b.pb({n, n});
    b.pb({n, 1});

    vector<int> maxx;
    pt shift = {1, 0};
    maxx.pb(get(b[0], b[1], shift, 2));
    //cout << "found maxx " << maxx.back() << "\n";
    maxx.pb(get(b[0], b[1], shift, 1));
    //cout << "found maxx " << maxx.back() << "\n";

    vector<int> minx;
    shift = {-1, 0};
    minx.pb(n - get(b[2], b[3], shift, 2) + 1);
    //cout << "found minx " << minx.back() << "\n";
    minx.pb(n - get(b[2], b[3], shift, 1) + 1);
    //cout << "found minx " << minx.back() << "\n";

    vector<int> miny;
    shift = {0, -1};
    miny.pb(n - get(b[1], b[2], shift, 2) + 1);
    //cout << "found miny " << miny.back() << "\n";
    miny.pb(n - get(b[1], b[2], shift, 1) + 1);
    //cout << "found miny " << miny.back() << "\n";

    vector<int> maxy;
    shift = {0, 1};
    maxy.pb(get(b[3], b[0], shift, 2));
    //cout << "found maxy " << maxy.back() << "\n";
    maxy.pb(get(b[3], b[0], shift, 1));
    //cout << "found maxy " << maxy.back() << "\n";

    for (int i1 = 0; i1 < 2; ++i1) {
        for (int j1 = 0; j1 < 2; ++j1) {
            for (int i2 = 0; i2 < 2; ++i2) {
                for (int j2 = 0; j2 < 2; ++j2) {
                    int xl = minx[i1], xr = maxx[i2];
                    int yl = miny[j1], yr = maxy[j2];
                    if (ok(xl, yl, xr, yr)) {
                        cout << "! " << xl << " " << yl << " " << xr << " " << yr << " " << minx[1 - i1] << " " << miny[1 - j1] << " " << maxx[1 - i2] << " " << maxy[1 - j2] << "\n";
                        cout.flush();
                        return 0;
                    }
                }
            }
        }
    }

}