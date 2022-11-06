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
typedef pair<ld, ld> pdd;

int n;
pii X[1001];
pii A[1001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    llong Xs = 0, Ys = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> X[i].fs >> X[i].se;
        Xs += X[i].fs;
        Ys += X[i].se;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> A[i].fs >> A[i].se;
        Xs += A[i].fs;
        Ys += A[i].se;
    }
    printf("%lld %lld\n", Xs / n, Ys / n);
    return 0;
}