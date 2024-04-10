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

int n;
char D[200002];
vector<int> num[10];
void solve() {
    cin >> n >> D + 1;
    for (int i = 0; i < 10; ++i) num[i].clear();
    for (int i = 1; i <= n; ++i) {
        num[D[i] - '0'].push_back(i);
    }
    for (int i = 0; i < 10; ++i) {
        bool pos = 1;
        int L = 0;
        for (int j = 0; j < i; ++j) {
            if (num[j].empty()) continue;
            if (num[j][0] <= L) {
                pos = 0;
                break;
            }
            L = num[j].back();
        }
        if (!pos) continue;
        int F = n + 1;
        for (int j = 9; j > i; --j) {
            if (num[j].empty()) continue;
            if (F <= num[j].back()) {
                pos = 0;
                break;
            }
            F = num[j][0];
        }
        if (!pos) continue;
        auto it = lower_bound(num[i].begin(), num[i].end(), F);
        if (it != num[i].end() && *it <= L) continue;
        for (int j = 1; j <= n; ++j) {
            if (D[j] < i + '0') D[j] = '1';
            else if (D[j] > i + '0') D[j] = '2';
            else if (j < F) D[j] = '2';
            else D[j] = '1';
        }
        printf("%s\n", D + 1);
        return;
    }
    printf("-\n");
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}