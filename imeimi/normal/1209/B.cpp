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
int B[101];
char on[101];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> on + 1;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i] >> B[i];
    }
    int ans = 0;
    for (int i = 0; i <= 1000000; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) cnt += on[j] == '1';
        ans = max(ans, cnt);
        for (int j = 1; j <= n; ++j) {
            if (B[j] <= i && (i - B[j]) % A[j] == 0) {
                on[j] ^= 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}