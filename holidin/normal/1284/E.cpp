#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;
const int mod = 1e9 + 7;
const long double PI = acos(-1);
const long double PI1 = 3.141592653589793238462643383279;
int x[N], y[N];

int plpl(int x, int y) {
    if ((y == 0 && x > 0) || (y > 0))
        return 0;
    else
        return 1;
}

int vec(const pair<int, int> &a, const pair<int, int> &b) {
    return a.fi * b.se - a.se * b.fi;
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (plpl(a.fi, a.se) == plpl(b.fi, b.se))
        return vec(a, b) > 0;
    else
        return plpl(a.fi, a.se) < plpl(b.fi, b.se);
}

int count_tr(int n) {
    int i, j, k;
    int ans = 0;
    for (i = 0; i < n; ++i) {
        vector <pair<int, int> > v;
        for (j = 0; j < n; ++j)
        if (i != j) {
            v.push_back({x[j] - x[i], y[j] - y[i]});
        }
        sort(v.begin(), v.end(), cmp);
        for (j = 0; j < n - 1; ++j) {
            v.push_back(v[j]);
        }
        int uk = 0;
        int cnt = 0;
        for (j = 0; j < n - 1; ++j) {
            if (uk == j)
                ++uk;
            while (uk < v.size() && vec(v[j], v[uk]) > 0)
                ++uk;
            int ct = uk - j;
            cnt += ((ct - 1) * (ct - 2)) / 2;
        }
        ans += (n - 1) * (n - 2) * (n - 3) / 6 - cnt;
    }
    return ans;
}


void solve() {
    int i, j, k, n, m, q;
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    cout << (n - 4) * count_tr(n) / 2;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);

    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}