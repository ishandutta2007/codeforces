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
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

int n, x, y;
int B[100001];
vector<int> C[100002];
vector<int> cnt[100002];
int ans[100001];
void solve() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n + 1; ++i) C[i].clear(), cnt[i].clear();
    for (int i = 1; i <= n; ++i) {
        cin >> B[i];
        ans[i] = 0;
        C[B[i]].push_back(i);
    }
    int e = 0;
    for (int i = 1; i <= n + 1; ++i) {
        if (C[i].empty()) e = i;
        cnt[C[i].size()].push_back(i);
    }
    for (int i = 0, j = n; i < x; ++i) {
        while (cnt[j].empty()) --j;
        int c = cnt[j].back();
        cnt[j].pop_back();
        int x = C[c].back();
        ans[x] = c;
        C[c].pop_back();
        cnt[C[c].size()].push_back(c);
    }
    int h = (n - x) / 2;
    vector<int> L;
    for (int i = 1; i <= n + 1; ++i) for (int j : C[i]) L.push_back(j);
    int it, i;
    for (it = x, i = 0; it < y && i < n - x; ++it, ++i) {
        int p = i, q = (i + h) % (n - x);
        if (B[L[q]] == B[L[p]]) {
            --it;
            continue;
        }
        ans[L[p]] = B[L[q]];
    }
    if (it < y) return (void)printf("NO\n");
    printf("YES\n");
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i] ? ans[i] : e);
    }
    printf("\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}