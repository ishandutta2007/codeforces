#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 2;
const long double e = 1e-8;
const long double inf = 1e18;

long double k[N], l[N], r[N], dp[N], b[N];
long long x[N], y[N], a[N], top;

int main() {
    int i, j, n;
    vector <pair<pair<long long, long long>, long long> > v;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i] >> a[i];
        v.push_back({{x[i], y[i]}, a[i]});
    }
    v.push_back({{0, 0}, 0});
    sort(v.begin(), v.end());
    k[0] = -v[0].fi.fi;
    b[0] = 0;
    dp[0] = 0;
    l[0] = -inf;
    r[0] = inf;
    top = 0;
    long double ans = 0;
    for (i = 1; i <= n; ++i) {
        long long T = v[i].fi.se;
        int l1 = 0, r1 = top + 1;
        while (r1 - l1 > 1) {
            int x = (l1 + r1) / 2 - 1;
            if (T < l[x])
                l1 = x + 1;
            else
                r1 = x + 1;
        }
        dp[i] = k[l1] * T + b[l1] + T * v[i].fi.fi - v[i].se;
        ++top;
        k[top] = -v[i].fi.fi;
        b[top] = dp[i];
        l[top] = -inf;
        r[top] = -inf;
        while (top > 0 && k[top - 1] * l[top - 1] + b[top - 1] < k[top] * l[top - 1] + b[top] - e) {
            if (k[top - 1] * r[top - 1] + b[top - 1] < k[top] * r[top - 1] + b[top] - e) {
                k[top - 1] = k[top];
                b[top - 1] = b[top];
                l[top - 1] = l[top];
                --top;
            } else {
                long double y = (b[top - 1] - b[top]) / (k[top] - k[top - 1]);
                l[top - 1] = y;
                r[top] = y;
                break;
            }
        }
        ans = max(ans, dp[i]) ;
    }
    cout << fixed << setprecision(0) << ans + e;
}