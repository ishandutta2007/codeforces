#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define uniq(x) x.resize(unique(x.begin(), x.end()) - x.begin())
using namespace std;
const int N = 4e5 + 52;

int m[N], a[N], n;


int f(int i) {
    return i & (-i);
}

int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += m[i];
        i -= f(i);
    }
    return ans;
}

void fenw(int i, int j) {
    while (i <= n) {
        m[i] += j;
        i += f(i);
    }
}

void solve() {
    int i, j, k, b;
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i < n; ++i)
        fenw(i + 1, i);
    vector <int> ans;
    for (i = n; i >= 1; --i) {
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (sum(mid) > a[i])
                r = mid;
            else
                l = mid;
        }
        fenw(l + 1, -l);
        ans.push_back(l);
    }
    for (i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << ' ';
}

signed main() {
    int i, test;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}