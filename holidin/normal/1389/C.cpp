#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;
const int mod = 1e9 + 7;

int a[N], t[N], pr[N];

void solve() {
    int i, j, k, n, l, r, z, ans = N;
    string s;
    cin >> s;
    for (int first = '0'; first <= '9'; ++first)
    for (int second = '0'; second <= '9'; ++second) {
        char last = second;
        int cnt = 0;
        for (auto c : s)
        if ((c == first || c == second) && (c != last || first == second)) {
            last = c;
            ++cnt;
        }
        if (first == second || cnt % 2 == 0)
            ans = min(ans, s.size() - cnt);
        else
            ans = min(ans, s.size() - cnt + 1);
    }
    cout << ans << "\n";

}

signed main() {
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int test = 0;
    cin >> test;
    for (int i = 0; i < test; ++i)
    solve();
}