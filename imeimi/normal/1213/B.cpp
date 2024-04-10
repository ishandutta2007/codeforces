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
int A[150001];
int solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    int mn = 10000000, ret = 0;
    for (int i = n; i > 0; --i) {
        if (mn < A[i]) ++ret;
        else mn = A[i];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}