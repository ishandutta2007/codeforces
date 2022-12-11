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

struct pt
{
    ll x, y, t;
    ld prob;
    bool operator<(const pt& other) const
    {
        return t < other.t;
    }
};

ll dist2(const pt& a, const pt& b)
{
    return (a.x - b.x)* (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].t >> p[i].prob;
    }

    sort(all(p));
    vector<ld> dp(n);
    ld ans = 0;

    for (int i = 0; i < n; ++i) {
        dp[i] = p[i].prob;
        for (int j = 0; j < i; ++j) {
            ll d2 = dist2(p[i], p[j]);
            ll dt = p[i].t - p[j].t;
            if (d2 <= dt * dt) {
                dp[i] = max(dp[i], dp[j] + p[i].prob);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << fixed;
    cout.precision(6);
    cout << ans << "\n";

}