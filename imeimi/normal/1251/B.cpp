#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n;
char in[51][51];
int solve() {
    cin >> n;
    vector<int> L;
    int cnt[2] = {};
    for (int i = 1; i <= n; ++i) {
        cin >> in[i];
        int k = strlen(in[i]);
        L.push_back(k);
        for (int j = 0; j < k; ++j) {
            ++cnt[in[i][j] - '0'];
        }
    }
    sort(L.begin(), L.end());
    int need1 = 0, need2 = 0, ans = 0;
    for (int i : L) {
        need1 += i & 1;
        need2 += i >> 1;
        if ((cnt[0] >> 1) + (cnt[1] >> 1) < need2
            || cnt[0] + cnt[1] < need1 + (need2 << 1)) break;
        ++ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}