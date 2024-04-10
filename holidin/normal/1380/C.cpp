#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 1;

map<char, int> m;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    int cnt = 0, tcnt = 0;
    int l = 0;
    while (l < n) {
        tcnt++;
        if (a[l] * tcnt >= x) {
            ++cnt;
            tcnt = 0;
        }
        ++l;
    }
    cout << cnt << "\n";
}


signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    cin >> test;
    for (; test > 0; test--)
        solve();
}