#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, int> pll;

const ld eps = 1e-9;
const ld inf = 1e18;

bool lt(ld a, ld b)
{
    return b - a > eps;
}

struct pt
{
    ld x, y;
    int id;
    bool operator<(const pt& other) const
    {
        if (y != other.y) {
            return y == 0;
        }
        return x < other.x;
    }
};

ld dist(const pt& a, const pt& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, k;
    cin >> n >> k;
    --k;
    vector<pt> p(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> p[i].x;
        p[i].y = 0;
        p[i].id = i;
    }
    cin >> p[n].y;

    sort(all(p));
    for (int i = 0; i <= n; ++i) {
        if (p[i].id == k) {
            k = i;
            break;
        }
    }

    cout << fixed;
    cout.precision(12);

    ld ans = 0;
    if (k == n) {
        ld val1 = dist(p[0], p[n]);
        ld val2 = dist(p[n - 1], p[n]);
        if (lt(val1, val2)) {
            ans = val1 + p[n - 1].x - p[0].x;
        } else {
            ans = val2 + p[n - 1].x - p[0].x;
        }
        cout << ans << "\n";
        return 0;
    }

    ans = inf;
    for (int i = 0; i <= k; ++i) {
        ld val1 = p[k].x - p[i].x + p[n - 1].x - p[i].x + dist(p[n - 1], p[n]);
        ld val2 = p[n - 1].x - p[k].x + p[n - 1].x - p[i].x + dist(p[i], p[n]);
        ld relax;
        if (lt(val1, val2)) {
            relax = val1;
        } else {
            relax = val2;
        }
        if (i) {
            val1 = dist(p[n], p[i - 1]) + p[i - 1].x - p[0].x;
            val2 = dist(p[n], p[0]) + p[i - 1].x - p[0].x;
            if (lt(val1, val2)) {
                relax += val1;
            } else {
                relax += val2;
            }
        }
        if (lt(relax, ans)) {
            ans = relax;
        }
    }

    for (int i = k; i < n; ++i) {
        ld val1 = p[k].x - p[0].x + p[i].x - p[0].x + dist(p[i], p[n]);
        ld val2 = p[i].x - p[k].x + p[i].x - p[0].x + dist(p[0], p[n]);
        ld relax;
        if (lt(val1, val2)) {
            relax = val1;
        } else {
            relax = val2;
        }
        if (i != n - 1) {
            val1 = dist(p[n], p[i + 1]) + p[n - 1].x - p[i + 1].x;
            val2 = dist(p[n], p[n - 1]) + p[n - 1].x - p[i + 1].x;
            if (lt(val1, val2)) {
                relax += val1;
            } else {
                relax += val2;
            }
        }
        if (lt(relax, ans)) {
            ans = relax;
        }
    }
    cout << ans << "\n";

}