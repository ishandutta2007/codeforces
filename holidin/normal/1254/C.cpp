#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;
const int inf = 1e9 + 1;
const int mod = 1e9 + 7;

mt19937 rnd(58);

int x[N], y[N];

int vect(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}

int get_vect(int i, int j, int k) {
    #ifdef local
        return abs(vect(x[j] - x[i], y[j] - y[i], x[k] - x[i], y[k] - y[i]));
    #endif // local
    cout << 1 << ' ' << i << ' ' << j << ' ' << k << endl;
    int ans;
    cin >> ans;
    return ans;
}

int get_sign(int i, int j, int k) {
    #ifdef local
        return vect(x[j] - x[i], y[j] - y[i], x[k] - x[i], y[k] - y[i]) > 0 ? 1 : -1;
    #endif // local
    cout << 2 << ' ' << i << ' ' << j << ' ' << k << endl;
    int ans;
    cin >> ans;
    return ans;
}


void solve() {
    int i, j, k, n, x1, y1;
    cin >> n;
    #ifdef local
        for (i = 1; i <= n; ++i)
            cin >> x[i] >> y[i];
    #endif // local
    int pos = 2;
    for (i = 3; i <= n; ++i)
    if (get_sign(2, 1, i) > 0) {
        pos = i;
        break;
    }
    if (pos != 2)
        for (i = pos + 1; i <= n; ++i)
        if (get_sign(1, pos, i) < 0) {
            pos = i;
        }
    vector <pair<int, int> > v;
    for (i = 2; i <= n; ++i)
    if (i != pos) {
        v.push_back({get_vect(1, pos, i), i});
    }
    sort(v.begin(), v.end());
    vector <int> fr, sc;
    for (i = 0; i < v.size() - 1; ++i)
    if (get_sign(v.back().se, 1, v[i].se) > 0)
        fr.push_back(v[i].se);
    else
        sc.push_back(v[i].se);
    cout << 0 << ' ' << 1 << ' ' << pos;
    for (i = 0; i < fr.size(); ++i)
        cout << ' ' << fr[i];
    cout << ' ' << v.back().se;
    for (i = (int) sc.size() - 1; i >= 0; --i)
        cout << ' ' << sc[i];
    cout << endl;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    //ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}