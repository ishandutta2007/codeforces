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

struct pt
{
    ll x, y;
};

const ll inf = 1e18;

ll dist(const pt& a, const pt& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;
    pt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    ll r = 0;
    for (int i = 0; i < n; ++i) {
        r = max(r, dist(p[i], b));
    }
    ll ans = r;

    for (int i = 0; i < n; ++i) {
        ll r1 = dist(a, p[i]);
        ll r2 = 0;
        for (int j = 0; j < n; ++j) {
            if (dist(p[j], a) > r1) {
                r2 = max(r2, dist(p[j], b));
            }
        }
        if (ans > r1 + r2) {
            ans = r1 + r2;
        }
    }

    cout << ans << "\n";

}