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

int n, k;
vector<int> A[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int x, cnt = 0;
        cin >> x;
        while (x) {
            A[x].push_back(cnt++);
            if (x == 0) break;
            x >>= 1;
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= 200000; ++i) {
        sort(A[i].begin(), A[i].end());
        if (A[i].size() < k) continue;
        int sum = 0;
        for (int j = 0; j < k; ++j) sum += A[i][j];
        ans = min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}