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
llong s;
int L[200001];
int R[200001];

bool check(int md) {
    int k = n + 1 >> 1;
    vector<int> M;
    for (int i = 1; i <= n; ++i) {
        int v = max(L[i], md);
        if (R[i] < v) continue;
        M.push_back(v - L[i]);
    }
    if ((int)M.size() < k) return 0;
    sort(M.begin(), M.end());
    llong sum = 0;
    for (int i = 0; i < k; ++i) sum += M[i];
    return sum <= s;
}

llong solve() {
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> L[i] >> R[i];
        s -= L[i];
    }
    int st = 0, ed = 1e9;
    while (st < ed) {
        int md = (st + ed + 1) / 2;
        if (check(md)) st = md;
        else ed = md - 1;
    }
    return st;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%lld\n", solve());
    return 0;
}