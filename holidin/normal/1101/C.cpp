#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 6e5 + 1;
const int inf = 1e9;
int t[N];
vector <pair<pair<int, int>, int> > v;

int main() {
    int i, j, l, r, q, d, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> q;
    for (int u = 0; u < q; ++u) {
        cin >> n;
        v.clear();
        for (i = 0; i < n; ++i) {
            cin >> l >> r;
            v.push_back({{l, r}, i});
            t[i] = 2;
        }
        sort(v.begin(), v.end());
        r = v[0].fi.se;
        t[v[0].se] = 1;
        int ku = -1;
        for (i = 1; i < v.size(); ++i)
        if (v[i].fi.fi > r) {
            ku = i;
            break;
        } else {
            r = max(r, v[i].fi.se);
            t[v[i].se] = 1;
        }
        if (ku < 0)
            cout << -1 << "\n";
        else {
            for (i = 0; i < n; ++i)
                cout << t[i] << ' ';
            cout << "\n";
        }
    }
}