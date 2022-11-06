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

int modular(llong x, int m) {
    int ret = x % m;
    while (ret < 0) ret += m;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    llong p;
    int k;
    cin >> p >> k;
    vector<int> ans;
    for (int i = 0; p; ++i) {
        int m = modular(p, k);
        ans.push_back(m);
        p -= m;
        p /= k;
        p = -p;
    }
    printf("%u\n", ans.size());
    for (int i : ans) printf("%d ", i);
    return 0;
}