#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = (int)1.01e9;

int main() {
#ifdef HOME
    freopen("L.in", "r", stdin);
#endif

    int n, k, m;
    while (scanf("%d%d%d", &n, &k, &m) == 3) {
        vector<int> x(k);
        for (int i = 0; i < k; i++) scanf("%d", &x[i]);

        vector<ll> t(m);
        vector<int> a(m), b(m);
        for (int i = 0; i < m; i++) {
            scanf("%lld%d%d", &t[i], &a[i], &b[i]);
        }

        set<pair<int, pair<ll, int> > > st1;
        for (int i = 0; i < k; i++) {
            st1.insert({x[i], {0, i}});
        }
        set<pair<ll, pair<int, int> > > st2;

        vector<pair<int, ll> > ans(m);
        for (int i = 0; i < m; i++) {
            while (!st2.empty() && st2.begin()->first <= t[i]) {
                auto o = *st2.begin();
                st2.erase(st2.begin());
                st1.insert({o.second.first, {o.first, o.second.second}});
            }
            if (st1.empty()) {
                ll ct = st2.begin()->first;
                while (!st2.empty() && st2.begin()->first == ct) {
                    auto o = *st2.begin();
                    st2.erase(st2.begin());
                    st1.insert({o.second.first, {o.first, o.second.second}});
                }
            } 
            auto it = st1.lower_bound({a[i], {-1, -1}});
            pair<int, pair<ll, int> > cur = {INF, {0, 0}};
            if (it != st1.end()) {
                cur = *it;
            }
            if (it != st1.begin()) {
                it--;
                it = st1.lower_bound({it->first, {-1, -1}});
                auto ncur = *it;
                auto cur1 = cur; cur1.first -= a[i];
                auto ncur1 = ncur; ncur1.first = a[i] - ncur1.first;
                if (ncur1 < cur1) cur = ncur;
            }
            st1.erase(cur);

            ans[i].first = cur.second.second + 1;
            ans[i].second = abs(cur.first - a[i]) + max(0LL, cur.second.first - t[i]);
            st2.insert({t[i] + ans[i].second + abs(a[i] - b[i]), {b[i], cur.second.second}});
        }
        for (int i = 0; i < m; i++) printf("%d %lld\n", ans[i].first, ans[i].second);
    } 
    
    return 0;
}