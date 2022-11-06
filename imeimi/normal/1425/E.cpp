#include <bits/stdc++.h>

using namespace std;
typedef long long llong;

int n, k;
int A[100005], D[100005], M[100005];
llong S[100005], L[100005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i <= n; ++i) cin >> D[i];
    llong ans = 0;
    for (int i = n; i > 0; --i) {
        S[i] = S[i + 1] + A[i];
        if (k != 1 || i > 1) {
            ans = max(ans, S[i] - D[i]);
        }
    }
    M[0] = 1e9;
    for (int i = 1; i <= n; ++i) M[i] = min(M[i - 1], D[i]);
    if (k >= 1) {
        llong mx = 0;
        for (int i = n - 1; i > 1; --i) {
            mx = max(mx, S[i + 1] - D[i + 1]);
            ans = max(ans, S[1] - S[i + 1] - M[i] + mx);
        }
        for (int i = 1; i <= n; ++i) L[i] = max(L[i - 1], S[i] - D[i]);
        for (int i = n - 1; i > 1; --i) {
            ans = max(ans, L[i - 1] - min(A[i], D[i]));
        }
    }
    if (k >= 2) {
        ans = max(ans, S[1] - M[n - 1]);
    }
    printf("%lld\n", ans);
    return 0;
}