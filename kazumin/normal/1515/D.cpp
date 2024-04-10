#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int t, n, l, r, c[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        vector<int> ls, rs;
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
            if (i <= l) ls.push_back(c[i]);
            else rs.push_back(c[i]);
        }
        if (l > r) swap(l, r), swap(ls, rs);
        int ch = (r - l) / 2; //change ch right socks to left ones
        multiset<int> L;
        for (int p : ls) L.insert(p);
        vector<int> v, reml, remr;
        for (int p : rs) {
            if (L.count(p)) L.erase(L.find(p));
            else v.push_back(p);
        }
        int ans = 0;
        sort(v.begin(), v.end());
        int pre = -1, cnt = 0;
        for (int p : v) {
            if (p != pre) {
                while (cnt >= 2 && ch) cnt -= 2, ch--;
                for (int i = 0; i < cnt; i++) remr.push_back(pre);
                cnt = 0, pre = p;
            }
            cnt++;
        }
        while (cnt >= 2 && ch) cnt -= 2, ch--;
        for (int i = 0; i < cnt; i++) remr.push_back(pre);
        for (int p : L) reml.push_back(p);
        ans = (remr.size() + reml.size()) / 2;
        printf("%lld\n", ans + (r - l) / 2);
    }

    return 0;
}