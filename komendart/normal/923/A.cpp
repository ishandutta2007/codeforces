#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

const int maxn = 1e6 + 6;

char used[maxn];
int L[maxn];

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    for (int i = 2; i < maxn; ++i) {
        L[i] = i;
    }
    for (int i = 2; i < maxn; ++i) {
        if (used[i]) continue;
        L[i] = i;
        for (int j = i + i; j < maxn; j += i) {
            used[j] = true;
            L[j] = min(L[j], j - i + 1);
        }
    }
    int X;
    cin >> X;
    int ans = X;
    for (int i = L[X]; i <= X; ++i) {
        ans = min(ans, L[i]);
    }
    ans = max(ans, 3);
    cout << ans << '\n';
}