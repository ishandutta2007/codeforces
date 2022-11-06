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
int A[101];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    sort(A + 1, A + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (A[i] == 0) continue;
        for (int j = i + 1; j <= n; ++j) {
            if (A[j] % A[i] == 0) A[j] = 0;
        }
        A[i] = 0;
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}