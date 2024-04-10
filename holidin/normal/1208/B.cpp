#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define uniq(x) x.resize(unique(x.begin(), x.end()) - x.begin())
using namespace std;
const int N = 2e5 + 52;

unordered_set<int> s;
int a[N];

void solve() {
    int i, j, k,n, b;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = n;
    for (i = 0; i < n; ++i) {
        s.clear();
        bool can = 1;
        for (j = 1; j <= i; ++j) {
            if (s.find(a[j]) != s.end())
                can = 0;
            s.insert(a[j]);
        }
        if (can)
            ans = min(ans, n - i);
        for (j = n; j > i; --j) {
            if (s.find(a[j]) != s.end())
                can = 0;
            s.insert(a[j]);
            if (can) {
                ans = min(ans, j - i - 1);
            }
        }
    }
    cout << ans;
}

signed main() {
    int i, test;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}