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

int n;
vector<int> edge[200001];

llong ans = 0;
int cnt[2][200001];
llong sum[2][200001];
void dfs(int x, int p) {
    cnt[0][x] = 1;
    sum[0][x] = 0;
    cnt[1][x] = 0;
    sum[1][x] = 0;
    for (int i : edge[x]) {
        if (i == p) continue;
        dfs(i, x);
        ans += sum[0][i] * cnt[0][x];
        ans += sum[0][i] * cnt[1][x];
        ans += sum[1][i] * cnt[0][x];
        ans += (sum[1][i] - cnt[1][i]) * cnt[1][x];
        ans += sum[0][x] * cnt[0][i];
        ans += sum[0][x] * cnt[1][i];
        ans += sum[1][x] * cnt[0][i];
        ans += sum[1][x] * cnt[1][i];
        cnt[0][x] += cnt[0][i];
        cnt[1][x] += cnt[1][i];
        sum[0][x] += sum[0][i];
        sum[1][x] += sum[1][i];
    }
    sum[0][x] += cnt[0][x];
    swap(sum[0][x], sum[1][x]);
    swap(cnt[0][x], cnt[1][x]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}