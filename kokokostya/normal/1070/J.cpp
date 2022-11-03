#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <cassert>
#include <numeric>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXLEN = 2e5 + 5;
const ll inf64 = 1e18;
const int N = 6e4 + 5;

char buffer[MAXLEN];

vector< int > get(const vector< int > &a, int k) {
    vector< int > dp(k + 1);
    dp[0] = 1;
    for(int x : a) {
        for(int j = k;j >= x;j--) {
            dp[j] |= dp[j - x];
        }
    }
    return dp;
}

void solve() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    scanf("%s", buffer);
    vector< int > cnt(26);
    for(int i = 0;i < k;i++) {
        int x = buffer[i] - 'A';
        cnt[x]++;
    }
    vector< int > dp = get(cnt, k);
    for(int x = n;x <= k;x++) {
        if(dp[x] && k - x >= m) {
            puts("0");
            return;
        }
    }
    ll res = inf64;
    for(int i = 0;i < 26;i++) {
        vector< int > hlp = cnt;
        swap(hlp[i], hlp[25]);
        hlp.pop_back();

        dp = get(hlp, k);
        vector< int > arr;

        for(int x = 0;x <= k;x++) {
            if(dp[x]) arr.push_back(x);
        }

        for(int j = (int)arr.size() - 1, x = 0;x <= cnt[i] && x <= n;x++) {
            while(j > 0 && arr[j - 1] >= n - x) j--;
            if(arr[j] >= n - x) {
                if(k - arr[j] - x >= m) {
//                    cout << 1ll * x * min(m, cnt[i] - x) << " : " << i << ", x = " << x << "\n";
                    int ost = k - arr[j] - cnt[i];
                    int tmp = max(0, m - ost);
                    if(tmp <= cnt[i] - x)
                        res = min(res, 1ll * x * tmp);
                }
            }
        }
    }
    printf("%lld\n", res);
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    int T;

    scanf("%d", &T);

    while(T--) solve();

    return 0;
}