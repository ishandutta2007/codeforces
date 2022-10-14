#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 5005;

llint t, n, curr, sol;
llint a[MAXN], b[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) curr += a[i] * b[i];
    sol = curr;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int lo = i - j, hi = i + j;
            if (lo < 1 || hi > n) break;
            curr -= a[lo] * b[lo] + a[hi] * b[hi] - a[lo] * b[hi] - a[hi] * b[lo];
            sol = max(sol, curr);
        }
        for (int j = 1; j <= n; j++) {
            int lo = i - j, hi = i + j;
            if (lo < 1 || hi > n) break;
            curr += a[lo] * b[lo] + a[hi] * b[hi] - a[lo] * b[hi] - a[hi] * b[lo];
        }
        for (int j = 1; j <= n; j++) {
            int lo = i - j + 1, hi = i + j;
            if (lo < 1 || hi > n) break;
            curr -= a[lo] * b[lo] + a[hi] * b[hi] - a[lo] * b[hi] - a[hi] * b[lo];
            sol = max(sol, curr);
        }
        for (int j = 1; j <= n; j++) {
            int lo = i - j + 1, hi = i + j;
            if (lo < 1 || hi > n) break;
            curr += a[lo] * b[lo] + a[hi] * b[hi] - a[lo] * b[hi] - a[hi] * b[lo];
        }
    }
    cout << sol;
    return 0;
}