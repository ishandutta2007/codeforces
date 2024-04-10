#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    rep(i, n) scanf("%d", &a[i]);
    vector <pair <int, int> > id;
    rep(i, n) id.pb(mp(a[i], i));
    sort(id.begin(), id.end());
    vector <int> re(n);
    rep(i, n) re[i] = id[i].second, a[i] = id[i].first;
    vector <int> b(n);
    rep(i, n) b[i] = i ? a[i] - a[i - 1] : a[i];
    vector <vector <pair <int, int> > > mx(n, vector <pair <int, int> > (n));
    for (int i = 0; i < n; ++ i) {
        pair <int, int> x = mp(0, -1);
        for (int j = i; j < n; ++ j) {
            x = max(x, mp(b[j], -j));
            mx[i][j] = mp(x.first, -x.second);
        }
    }
    pair <pair <int, int>, int> mxmx;
    int acnt1, acnt2, acnt3;
    auto updans = [&] (int cnt1, int cnt2, int cnt3) {
        pair <pair <int, int>, int> nw;
        nw = mp(mp(
                    b[n - cnt1],
                    b[n - cnt1 - cnt2]),
                    b[n - cnt1 - cnt2 - cnt3]);
        if (mxmx < nw) {
            mxmx = nw;
            acnt1 = cnt1;
            acnt2 = cnt2;
            acnt3 = cnt3;
        }
    };
    for (int cnt1 = 1; cnt1 <= n; ++ cnt1) {
        for (int cnt2 = 1; cnt1 + cnt2 <= n; ++ cnt2) {
            if (cnt1 > 2 * cnt2 || cnt2 > 2 * cnt1) continue;
            int cnt3l = 1, cnt3r = n - cnt1 - cnt2;
            cnt3l = max(cnt3l, (cnt1 + 1) / 2);
            cnt3l = max(cnt3l, (cnt2 + 1) / 2);
            cnt3r = min(cnt3r, 2 * cnt1);
            cnt3r = min(cnt3r, 2 * cnt2);
            if (cnt3l > cnt3r) continue;
            auto x = mx[n - cnt1 - cnt2 - cnt3r][n - cnt1 - cnt2 - cnt3l];
            int cnt3 = n - cnt1 - cnt2 - x.second;
            updans(cnt1, cnt2, cnt3);
        }
    }
    vector <int> ans(n);
    rep(i, n) ans[re[i]] = (
        i < n - acnt1 - acnt2 - acnt3 ? -1 : (
        i < n - acnt1 - acnt2 ? 3 : (
        i < n - acnt1 ? 2 : 1
        )
        )
    );
    rep(i, n) printf("%d ", ans[i]);
    return 0;
}