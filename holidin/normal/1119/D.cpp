#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N  = 2e5 + 1;
long long ans[N], sy[N];
vector <long long> v;
vector <pair<long long, long long> > qv;
set <pair<long long, int> > s;

int main() {
    int i, j, k, n, m, b, q;
    long long l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> sy[i];
        v.push_back(sy[i]);
    }
    sort(v.begin(), v.end());
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> l >> r;
        qv.push_back({r - l + 1, i});
    }
    sort(qv.begin(), qv.end());
    long long ansc = 0;
    for (i = 0; i < v.size() - 1; ++i)
    s.insert({v[i + 1] - v[i], i});
    for (i = 0; i < qv.size(); ++i) {
        while (s.size() > 0 && (*s.begin()).fi <= qv[i].fi) {
            ansc += v[(*s.begin()).second + 1] - v[(*s.begin()).second];
            s.erase(s.begin());
        }
        ans[qv[i].second] = ansc + qv[i].fi * ((long long) 1 + s.size());
    }
    for (i = 0; i < q; ++i)
        cout << ans[i] << ' ';
}