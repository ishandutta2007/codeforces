#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const llong inf = 1e18;
int n;
llong L[100001];
char S[100001];
llong F[6];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> L[i];
    cin >> S + 1;
    llong ans = 0;
    llong st = 0;
    for (int i = 1; i <= n; ++i) {
        ans += L[i];
        if (S[i] == 'G') {
            st -= L[i];
            F[2] += 2 * L[i];
            F[5] = inf;
        }
        else if (S[i] == 'W') {
            st -= L[i];
            F[1] += 2 * L[i];
            F[3] = inf;
        }
        else {
            st -= L[i];
        }
        for (int j = 1; j <= 5; ++j) {
            if (st < 0) {
                llong H = min(-st, F[j]);
                st += H;
                F[j] -= H;
                ans += H * j;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}