#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 1;

int a[N];
multiset <long long> s;
vector <pair<long long, long long> > v;

int main() {
    int i, j, k, n, q, t, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        cin >> t >> b;
        v.push_back({-b, t});
    }
    sort(v.begin(), v.end());
    long long tek = 0, ans = 0;
    for (i = 0; i < v.size(); ++i) {
        if (s.size() < k) {
            s.insert(v[i].se);
            tek += v[i].se;
        } else if (*s.begin() < v[i].se) {
                tek += v[i].se - *s.begin();
                s.erase(s.begin());
                s.insert(v[i].se);
            }
        ans = max(ans, -v[i].fi * tek);
    }
    cout << ans;
}