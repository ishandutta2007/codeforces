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
int A[100001];
int R[100001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        R[x] = i;
    }
    int mx = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (R[A[i]] < mx) {
            ++ans;
        }
        else {
            mx = R[A[i]];
        }
    }
    printf("%d\n", ans);
    return 0;
}