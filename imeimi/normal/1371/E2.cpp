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

int n, p, A[100000];
bool imp[100000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> p;
    for (int i = 0; i < n; ++i) cin >> A[i];
    sort(A, A + n);
    int mn = 0;
    for (int i = 0; i < n; ++i) mn = max(mn, A[i] - i);
    for (int i = 0; i < n; ++i) A[i] -= mn;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && A[j] <= i) ++j;
        int m = j % p;
        if (m <= i) imp[(i - m) % p] = 1;
    }
    vector<int> ans;
    for (int i = 0; i < p - 1; ++i) {
        if (imp[i]) continue;
        ans.push_back(i + mn);
    }
    printf("%u\n", ans.size());
    for (int i : ans) printf("%d ", i);
    return 0;
}