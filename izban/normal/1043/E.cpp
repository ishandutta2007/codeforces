#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld", &a[i].first, &a[i].second);
            a[i].first *= 2;
            a[i].second *= 2;
        }

        vector<pair<int, int>> b(m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &b[i].first, &b[i].second);
            b[i].first--;
            b[i].second--;
        }

        vector<ll> s(n);
        vector<pair<ll, int>> c(n);
        for (int i = 0; i < n; i++) {
            s[i] = (a[i].first + a[i].second) / 2;
            c[i] = {s[i] - a[i].second, i};
        }
        sort(c.begin(), c.end());

        vector<ll> pref(n + 1);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + c[i].first;
        vector<ll> suf(n + 1);
        for (int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] - c[i].first;

        ll allSum = 0;
        for (ll cs : s) allSum += cs;

        vector<ll> ans(n);
        for (int i = 0; i < n; i++) {
            int cntL = i, cntR = n - i - 1;
            ll cur = 0;
            int id = c[i].second;

            cur += allSum - s[id];
            cur += s[id] * (n - 1);

            cur += c[i].first * cntR + suf[i + 1];
            cur += -c[i].first * cntL + pref[i];
            ans[id] = cur;
        }

        for (auto o : b) {
            ll score = min(a[o.first].first + a[o.second].second, a[o.first].second + a[o.second].first);
            ans[o.first] -= score;
            ans[o.second] -= score;
        }
        for (auto &x : ans) {
            assert(x % 2 == 0);
            x /= 2;
        }

        for (int i = 0; i < n; i++) printf("%lld%c", ans[i], " \n"[i + 1 == n]);
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}