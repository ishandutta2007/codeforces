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

const int inf = 1e8;
int n, k;
int a[35001];
int pr[35001];
int lst[35001];
int dp[35001][51];
int seg[51][1 << 17];
int lazy[51][1 << 17];

void update(int t, int i, int s, int e, int x, int y, int v) {
    if (e < x || y < s) return;
    if (x <= s && e <= y) {
        seg[t][i] += v;
        lazy[t][i] += v;
        return;
    }
    int m = (s + e) / 2;
    update(t, i << 1, s, m, x, y, v);
    update(t, i << 1 | 1, m + 1, e, x, y, v);
    seg[t][i] = max(seg[t][i << 1], seg[t][i << 1 | 1]) + lazy[t][i];
}

int query(int t, int i, int s, int e, int x, int y) {
    if (e < x || y < s) return -inf;
    if (x <= s && e <= y) return seg[t][i];
    int m = (s + e) / 2;
    return max(query(t, i << 1, s, m, x, y), query(t, i << 1 | 1, m + 1, e, x, y)) + lazy[t][i];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pr[i] = lst[a[i]];
        lst[a[i]] = i;
	}
	
	for (int i = 1; i <= k; ++i) dp[0][i] = -inf;
	for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            update(j, 1, 0, n, pr[i], i - 1, 1);
        }
        update(0, 1, 0, n, i, i, -inf);
        for (int j = 1; j <= k; ++j) {
            int dp = query(j - 1, 1, 0, n, 0, i - 1);
            update(j, 1, 0, n, i, i, dp);
        }
	}
	
	printf("%d\n", query(k, 1, 0, n, n, n));
	
	return 0;
}