#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

const ll inf = 5e18;

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");
    //freopen("mine.txt", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);

    vector<ll> cost(n);
    vector<int> color(n);

    forn(i, n) {
        scanf("%I64d", &cost[i]);
    }
    forn(i, n) {
        scanf("%d", &color[i]);
        --color[i];
    }

    while (q--) {
        ll a, b;
        scanf("%I64d%I64d", &a, &b);
        if (n == 1) {
            ll ans = max((ll)0, cost[0] * b);
            printf("%I64d\n", ans);
            continue;
        }
        vector<ll> dp(n, -inf);
        pair<ll, int> p1, p2;
        p1 = {-inf - 1, 0};
        p2 = {-inf, n};
        ll ans = 0;
        forn(i, n) {
            ll x = cost[i] * b;
            ll upd = x;
            ll t = dp[color[i]];
            if (t != -inf) {
                ll y = t + cost[i] * a;
                upd = max(upd, y);
            }
            ll g = p2.first;
            if (p2.first == t && p2.second == 1) {
                g = p1.first;
            }
            if (g > -inf) {
                ll z = g + cost[i] * b;
                upd = max(upd, z);
            }
            if (t < upd) {
                if (p1.first == t) {
                    --p1.second;
                }
                if (p2.first == t) {
                    --p2.second;
                }
                if (p2.second == 0) {
                    p2 = p1;
                    p1 = {-inf - 1, 0};
                }
                if (upd > p2.first) {
                    p1 = p2;
                    p2 = mp(upd, 1);
                } else if (upd == p2.first) {
                    ++p2.second;
                } else if (upd > p1.first) {
                    p1 = mp(upd, 1);
                } else if (upd == p1.first) {
                    ++p1.second;
                }
                dp[color[i]] = upd;
                ans = max(ans, upd);
            }
        }
        printf("%I64d\n", ans);
    }

}