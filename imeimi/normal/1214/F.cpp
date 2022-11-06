#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#define fs first
#define se second

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

int m, n;
pii A[200000];
pii B[200000];
llong sum[400005];
llong sum2[400005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i].fs;
        A[i].se = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i].fs;
        B[i].se = i + 1;
    }
    sort(A, A + n);
    sort(B, B + n);
    for (int i = 0, j = 0, k = 0, l = 0; i < n; ++i) {
        while (j < n && A[j].fs < B[i].fs - m / 2) ++j;
        while (k < n && A[k].fs < B[i].fs) ++k;
        while (l < n && A[l].fs <= B[i].fs + m / 2) ++l;
        debug("B[%d] : %d ~ %d ~ %d\n", i, j, k, l);
        sum[n - i] += -(B[i].fs - m);
        sum[j + n - i] += (B[i].fs << 1) - m;
        sum[k + n - i] += -(B[i].fs << 1);
        sum[l + n - i] += (B[i].fs << 1);
        sum[l + n - i] += m;
        sum[n + n - i] += -(B[i].fs + m);
    }
    for (int i = 0, j = 0, k = 0, l = 0; i < n; ++i) {
        while (j < n && B[j].fs < A[i].fs - m / 2) ++j;
        while (k < n && B[k].fs <= A[i].fs) ++k;
        while (l < n && B[l].fs <= A[i].fs + m / 2) ++l;
        debug("A[%d] : %d ~ %d ~ %d\n", i, j, k, l);
        sum2[n - i] += -A[i].fs;
        sum2[j + n - i] += (A[i].fs << 1);
        sum2[k + n - i] += -(A[i].fs << 1);
        sum2[l + n - i] += (A[i].fs << 1);
        sum2[n + n - i] += -A[i].fs;
    }
    for (int i = 1; i < 400005; ++i) {
        sum[i] += sum[i - 1];
        sum2[i] += sum2[i - 1];
        if (i >= n) sum[i % n] += sum[i];
        if (i >= n) sum2[i % n] += sum2[i];
    }
    llong ans = 1e18;
    int mi = 0;
    for (int i = 0; i < n; ++i) {
        llong v = sum[i] + sum2[(n - i) % n];
        debug("%d : %lld %lld\n", i, sum[i], sum2[(n - i) % n]);
        if (v < ans) {
            mi = i;
            ans = v;
        }
    }
    debug("%d\n", mi);
    printf("%lld\n", ans);
    vector<int> v(n + 1);
    for (int i = 0; i < n; ++i) {
        pii a = A[(i + mi) % n];
        pii b = B[i];
        v[a.se] = b.se;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", v[i]);
    }
    return 0;
}