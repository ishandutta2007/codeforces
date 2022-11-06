#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    int x;
    cin >> x;
    int tmpw; cin >> tmpw;
    n--;
    vector< pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.rbegin(), a.rend());
    multiset<int> q;
    int ans = n + 1;
    int deleted = 0;
    int p = 0;
    while (true) {
        while (p < n && a[p].first > x) {
            q.insert(a[p].second - a[p].first + 1);
            p++;
        }
        ans = min(ans, p - deleted + 1);
        if (q.empty() || *q.begin() > x) break;
        x -= *q.begin();
        deleted++;
        q.erase(q.begin());
    }

    cout << ans << '\n';

}