#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, q;
int A[100001];
int D[200001];
int st;
pii ans[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        D[i] = A[i];
    }
    st = 1;
    for (int i = 1; i <= n; ++i) {
        int X = D[st], Y = D[st + 1];
        D[st + 1] = max(X, Y);
        D[st + n] = min(X, Y);
        ++st;
        ans[i] = pii(X, Y);
    }
    while (q--) {
        llong m;
        cin >> m;
        if (m <= n) printf("%d %d\n", ans[m].fs, ans[m].se);
        else printf("%d %d\n", D[st], D[st + (m - 2) % (n - 1) + 1]);
    }
    return 0;
}