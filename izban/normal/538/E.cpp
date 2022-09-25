#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std;

const int maxn = 1 << 18;
const int inf = 1e9;

int n;
int cnt[maxn];
int dp[maxn][2];
vector<int> e[maxn];

void dfs1(int v, int p) {
    vector<vector<int> > a(2);
    for (int i = 0; i < (int)e[v].size(); i++) {
        int to = e[v][i];
        if (to == p) continue;
        dfs1(to, v);
        cnt[v] += cnt[to];
        a[0].push_back(dp[to][1]);
        a[1].push_back(dp[to][0]);
    }
    if (cnt[v] == 0) {
        cnt[v] = 1;
        dp[v][0] = dp[v][1] = 0;
        return;
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    dp[v][0] = a[0][0];
    dp[v][1] = 0;
    for (int i = 0; i < (int)a[1].size(); i++) dp[v][1] += a[1][i];
    dp[v][1] += (int)a[1].size() - 1;
}

int dp2[maxn][2], cnt2[maxn];

void dfs2(int v, int p) {
    vector<vector<int> > a(2);
    for (int i = 0; i < (int)e[v].size(); i++) {
        int to = e[v][i];
        if (to == p) continue;
        dfs2(to, v);
        cnt2[v] += cnt2[to];
        a[0].push_back(dp2[to][1]);
        a[1].push_back(dp2[to][0]);
    }
    if (cnt2[v] == 0) {
        cnt2[v] = 1;
        dp2[v][0] = dp2[v][1] = 0;
        return;
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    dp2[v][1] = a[1][0];
    dp2[v][0] = 0;
    for (int i = 0; i < (int)a[0].size(); i++) dp2[v][0] += a[0][i];
    dp2[v][0] += (int)a[0].size() - 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//ios_base::sync_with_stdio(0);
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
            cnt[i] = cnt2[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs1(0, 0);
        dfs2(0, 0);
        cout << cnt[0] - dp[0][0] << " " << dp2[0][0] + 1 << endl;
    }


	return 0;
}