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

int cnt[256];
char in[100001];
int n;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> in;
    for (int i = 0; i < n; ++i) {
        ++cnt[in[i]];
    }
    pii ans = pii(-1, 0);
    for (int i = 0; i <= n; ++i) {
        int cnt1 = min({ i, cnt['o'], cnt['n'], cnt['e'] });
        int cnt0 = min({ cnt['z'], cnt['e'] - cnt1, cnt['r'], cnt['o'] - cnt1 });
        if (cnt['o'] != cnt1 + cnt0) continue;
        if (cnt['n'] != cnt1) continue;
        if (cnt['e'] != cnt1 + cnt0) continue;
        if (cnt['z'] != cnt0) continue;
        if (cnt['r'] != cnt0) continue;
        ans = max(ans, pii(cnt1 + cnt0, cnt1));
    }
    for (int i = 0; i < ans.fs; ++i) {
        if (i < ans.se) printf("1 ");
        else printf("0 ");
    }
}