#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
int main() {
    int n;
    cin >> n;
    vector<LL> b(n);
    int cnt[64] = {};
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        ++cnt[__builtin_ctzll(b[i])];
    }
    int ans = 0;
    for (int i = 1; i < 64; ++i)
        if (cnt[i] > cnt[ans])
            ans = i;
    cout << n - cnt[ans] << endl;
    for (int i = 0; i < n; ++i)
        if (__builtin_ctzll(b[i]) != ans)
            cout << b[i] << endl;
    return 0;
}