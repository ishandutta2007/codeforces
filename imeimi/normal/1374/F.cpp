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

int n;
int A[501];

void add(int i) {
    swap(A[i], A[i + 1]);
    swap(A[i], A[i + 2]);
}

void solve() {
    cin >> n;
    int cnt = 0, same = 0, a, b;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        for (int j = 1; j < i; ++j) {
            if (A[j] > A[i]) ++cnt;
            if (A[i] == A[j]) same = 1, a = i, b = j;
        }
    }
    if (!same && cnt % 2 == 1) {
        printf("-1\n");
        return;
    }
    vector<pii> P;
    for (int i = 1; i <= n; ++i) {
        P.emplace_back(A[i], i);
    }
    sort(P.begin(), P.end());
    for (int i = 1; i <= n; ++i) {
        A[P[i - 1].se] = i;
    }
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (A[j] > A[i]) ++cnt;
        }
    }
    if (cnt & 1) swap(A[a], A[b]);
    vector<int> ans;
    for (int v = n; v >= 1; --v) {
        int p;
        for (int i = 1; i <= v; ++i) if (A[i] == v) p = i;
        for (; p < v; ++p) {
            int i = max(1, min(p, v - 2));
            add(i);
            ans.push_back(i);
        }
    }
    printf("%u\n", ans.size());
    for (int i : ans) printf("%d ", i);
    printf("\n");
    for (int i = 1; i <= n; ++i) debug("%d", A[i]);
    debug("\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}