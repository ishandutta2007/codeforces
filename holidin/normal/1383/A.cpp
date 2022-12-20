#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int cnt[256], hcnt[256];


void solve() {
    int i, j, k ,n, m;
    cin >> n;
    string A, B;
    cin >> A >> B;
    for (char c = 'a'; c != 'z'; ++c)
        cnt[c] = 0;
    for (auto p : A)
        ++cnt[p];
    for (auto p : B)
        ++cnt[p];
    for (int i = 0; i < n; ++i)
    if (A[i] > B[i]) {
        cout << -1 << "\n";
        return;
    }
    int ans = 0;
    for (char c = 'a'; c != 'y'; ++c) {
        bool nchange = false, maxt = true;
        for (int i = 0; i < n; ++i) {
            nchange |= (A[i] == c && A[i] != B[i]);
        }
        for (char a = 'a'; a != 'y'; ++a)
            hcnt[a] = 0;
        for (int i = 0; i < n; ++i)
        if (A[i] == c)
            ++hcnt[B[i]];
        if (!nchange)
            continue;
        int next = c + 1;
        while (!hcnt[next])
            ++next;
        ++ans;
        for (int i = 0; i < n; ++i)
        if (A[i] == c && B[i] != c)
            A[i] = next;
    }
    cout << ans << "\n";
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test = 0;
    cin >> test;
    for (int i = 0; i < test; ++i)
        solve();
}