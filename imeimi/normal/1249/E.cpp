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

int n, c;
int A[200001];
int B[2000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> c;
    for (int i = 2; i <= n; ++i) {
        cin >> A[i];
    }
    for (int i = 2; i <= n; ++i) {
        cin >> B[i];
        B[i] += B[i - 1];
    }
    printf("0");
    int prv = 0, mnb= 0;
    for (int i = 2; i <= n; ++i) {
        int nxt = min(prv + A[i], mnb + B[i] + c);
        mnb = min(mnb, nxt - B[i]);
        prv = nxt;
        printf(" %d", nxt);
    }
    return 0;
}