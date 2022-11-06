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
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const int inf = 1e8;
const int L = 60;
int n;
llong A[100001];
vector<int> B[L];
int T[L + L + 1][L + L + 1];
int D[L + L + 1][L + L + 1];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    DEBUG("Hello World!\n");
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < L; ++j) {
            if ((A[i] >> j) & 1) {
                B[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < L; ++i) {
        if (B[i].size() > 2) {
            printf("3\n");
            return 0;
        }
    }
    sort(A + 1, A + (n + 1), greater<llong>());
    n = min(n, L + L);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i] & A[j]) T[i][j] = 1;
            else T[i][j] = inf;
        }
        T[i][i] = 0;
    }
    int ans = inf;
    for (int it = 1; it <= n; ++it) {
        for (int jt = 1; jt <= it; ++jt) {
            if (T[it][jt] != 1) continue;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    D[i][j] = inf;
                    if (i == it && j == jt) continue;
                    if (j == it && i == jt) continue;
                    D[i][j] = T[i][j];
                }
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    for (int k = 1; k <= n; ++k) {
                        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                    }
                }
            }
            ans = min(ans, D[it][jt] + 1);
        }
    }
    printf("%d\n", ans < inf ? ans : -1);
    return 0;
}