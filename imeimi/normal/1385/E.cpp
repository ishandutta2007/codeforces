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

int n, m;
int A[200001], B[200001];
vector<int> edge[200001];
int deg[200001], ord[200001];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        edge[i].clear();
        deg[i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int t;
        cin >> t >> A[i] >> B[i];
        if (!t) continue;
        edge[A[i]].push_back(B[i]);
        ++deg[B[i]];
    }
    vector<int> st;
    for (int i = 1; i <= n; ++i) if (deg[i] == 0) st.push_back(i);
    for (int i = 0; i < int(st.size()); ++i) {
        ord[st[i]] = i;
        for (int j : edge[st[i]]) {
            if (--deg[j] == 0) st.push_back(j);
        }
    }
    if (int(st.size()) < n) return (void)printf("NO\n");
    printf("YES\n");
    for (int i = 1; i <= m; ++i) {
        if (ord[A[i]] > ord[B[i]]) swap(A[i], B[i]);
        printf("%d %d\n", A[i], B[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}