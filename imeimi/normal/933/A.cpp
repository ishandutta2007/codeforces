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

struct value {
    int v[2][2];
    value() {
        v[0][0] = 0;
        v[0][1] = 0;
        v[1][0] = 0;
        v[1][1] = 0;
    }
    value(int x) {
        v[0][0] = 0;
        v[0][1] = 0;
        v[1][0] = 0;
        v[1][1] = 0;
        v[x][x] = 1;
        v[0][x] = 1;
        v[x][1] = 1;
    }
    value operator+(const value &p) const {
        value ret;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                ret.v[i][j] = max(v[i][i] + p.v[i][j], v[i][j] + p.v[j][j]);
            }
        }
        return ret;
    }
} pre[2001], suf[2002];

int A[2001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        pre[i] = pre[i - 1] + value(A[i] - 1);
    }
    for (int i = n; i > 0; --i) {
        suf[i] = value(A[i] - 1) + suf[i + 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        value sum = value();
        for (int j = i; j <= n; ++j) {
            sum = value(A[j] - 1) + sum;
            ans = max(ans, (pre[i - 1] + sum + suf[j + 1]).v[0][1]);
        }
    }
    printf("%d\n", ans);
    return 0;
}