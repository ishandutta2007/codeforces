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

const llong mx = 10004205361450474;
map<pii, llong> dp;

int ask(vector<llong> q) {
    printf("%d\n", (int)q.size());
    for (llong i : q) printf("%lld\n", i);
    fflush(stdout);
    
    int r;
    scanf("%d", &r);
    if (r < 0) exit(0);
    return r;
}

llong pro_dp(int q, llong s, int pr) {
    if (q == 0) return 0;
    int k = min(s, 10000ll);
    if (!pr && dp.find(pii(q, k)) != dp.end()) return dp[pii(q, k)];
    
    vector<llong> v;
    llong x = s;
    for (int i = 0; i < k; ++i) {
        x += pro_dp(q - 1, x, 0);
        v.push_back(x++);
    }
    
    if (pr) {
        int x = ask(v);
        if (x == 0) pro_dp(q - 1, s, 1);
        else pro_dp(q - 1, v[x - 1] + 1, 1);
    }
    return dp[pii(q, k)] = x + pro_dp(q - 1, x, 0) - s;
}

int main() {
    pro_dp(5, 1, 1);
	return 0;
}