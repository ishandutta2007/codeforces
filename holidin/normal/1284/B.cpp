#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;

vector <int> v[N], mx;
bool good[N];

void solve() {
    int i, j, k, n, m, q;
    cin >> n;
    int cntgood = 0;
    for (i = 0; i < n; ++i) {
        cin >> k;
        v[i].resize(k);
        for (j = 0; j < k; ++j)
            cin >> v[i][j];
        for (j = 1; j < k; ++j) {
            if (v[i][j - 1] < v[i][j])
                good[i] = 1;
        }
        sort(v[i].begin(), v[i].end());
        if (!good[i]) {
            mx.push_back(v[i].back());
        } else
            ++cntgood;
    }
    sort(mx.begin(), mx.end());
    int ans = 0;
    for (i = 0; i < n; ++i)
    if (good[i])
        ans += n;
    else {
        ans += cntgood;
        int l = 0, r = mx.size() + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2 - 1;
            if (v[i][0] < mx[mid])
                r = mid + 1;
            else
                l = mid + 1;
        }
        ans += mx.size() - l;
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