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
int A[300001];
vector<int> pos[300001];
int solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) pos[i].clear();
    vector<int> cp;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        cp.push_back(A[i]);
    }
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    for (int i = 1; i <= n; ++i) {
        A[i] = upper_bound(cp.begin(), cp.end(), A[i]) - cp.begin();
        pos[A[i]].push_back(i);
    }
    int m = cp.size();
    int ans = 1;
    for (int i = 1, j = 1; i <= m; ++i) {
        j = max(j, i);
        while (j + 1 <= m && pos[j].back() < pos[j + 1][0]) ++j;
        ans = max(ans, j - i + 1);
    }
    return m - ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}