#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 12;
int p[N];
int a[N], t[N];
vector <pair<int, int> > v;

void solve() {
    int i, j, k, n;
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    for (i = 0; i < n; ++i) {
        cin >> t[i];
        v.push_back({a[i], t[i]});
    }
    sort(v.begin(), v.end());
    multiset <pair<int, int> > s;
    i = 0;
    int ans = 0;
    while (i < v.size()) {
        j = i;
        int tim = v[i].fi;
        while (j < v.size() && v[j].fi == v[i].fi) {
            s.insert({-v[j].se, v[j].fi});
            ++j;
        }
        while (s.size() > 0) {
            auto p = *s.begin();
            s.erase(s.begin());
            ans += (tim - p.se) * -p.fi;
            ++tim;
            while (j < v.size() && v[j].fi <= tim) {
                s.insert({-v[j].se, v[j].fi});
                ++j;
            }
        }
        i = j;
    }
    cout << ans;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}