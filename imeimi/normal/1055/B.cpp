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

llong A[100005];
int par[100005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    int cnt = 0, ls = 0;
    for (int i = 1; i <= n; ++i) {
        if (A[i] > l) ++cnt;
        if (i > 1 && A[i] > l && A[i - 1] > l) ++ls;
    }
    while (m--) {
        int T;
        cin >> T;
        if (T == 1) {
            int a, b;
            cin >> a >> b;
            if (A[a] > l) continue;
            A[a] += b;
            if (A[a] > l) {
                ++cnt;
                if (a > 1 && A[a - 1] > l) ++ls;
                if (a < n && A[a + 1] > l) ++ls;
            }
        }
        else printf("%d\n", cnt - ls);
    }
    return 0;
}