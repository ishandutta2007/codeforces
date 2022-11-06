#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, m;
int A[11][100010];
int R[11][100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> A[i][j];
            R[i][A[i][j]] = j;
        }
    }
    llong ans = 0;
    for (int i = 1; i <= n; ) {
        int S[11];
        for (int j = 2; j <= m; ++j) {
            S[j] = R[j][A[1][i]];
        }
        llong cnt = 1;
        while (1) {
            int c = A[1][i + cnt];
            for (int j = 2; j <= m; ++j) {
                if (c != A[j][S[j] + cnt]) c = 0;
            }
            if (c == 0) break;
            ++cnt;
        }
        ans += cnt * (cnt + 1) / 2;
        i += cnt;
    }
    printf("%lld\n", ans);
    return 0;
}