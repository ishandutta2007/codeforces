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

bool check(int d, int n, llong k, vector<int> &A) {
    vector<int> B, cp;
    for (int i : A) {
        B.push_back(i - d);
    }
    cp.resize(A.size() + B.size());
    merge(A.begin(), A.end(), B.begin(), B.end(), cp.begin());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    debug("cp[%d]=", d);
    for (int i : cp) {
        debug("%d ", i);
    }
    debug("\n");
    int i = 0, j = 0;
    int ucnt = 0, dcnt = 0;
    llong usum = 0, dsum = 0;
    for (int i : A) {
        ++ucnt;
        usum += i;
    }
    for (int c : cp) {
        while (i < n && A[i] < c) {
            ++dcnt;
            dsum += A[i];
            ++i;
        }
        while (j < n && A[j] <= c + d) {
            --ucnt;
            usum -= A[j];
            ++j;
        }
        llong cost = (usum - (llong)ucnt * (c + d)) + ((llong)dcnt * c - dsum);
        debug("cost[%d]=%lld, usum=%lld, dsum=%lld\n", c, cost, usum, dsum);
        if (cost <= k) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int n;
    llong k;
    cin >> n >> k;
    vector<int> A;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    sort(A.begin(), A.end());
    int s = 0, e = 1e9 + 5;
    while (s < e) {
        int m = (s + e) / 2;
        if (check(m, n, k, A)) e = m;
        else s = m + 1;
    }
    printf("%d\n", s);
    return 0;
}