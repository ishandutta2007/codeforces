#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 100100;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, k, p;
vector<int> e[maxn];
int cnt[maxn];

void dfs(int v, int h = 0, int p = -1) {
    for (int i = 0; i < (int)e[v].size(); i++) {
        int to = e[v][i];
        if (to == p) continue;
        dfs(to, h + 1, v);
    }
    cnt[h]++;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    while (cin >> n >> k >> p) {
        for (int i = 0; i <= n; i++) {
            cnt[i] = 0;
            e[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1);
        
        int ans = 0;
        int res = 0;
        ll penalty = 0;
        int j = 1;
        for (int i = 1; i <= n; i++) {
            res += cnt[i];
            ans = max(ans, min(res, k));
            penalty += res;
            while (penalty > p) {
                while (cnt[j] == 0) j++;
                cnt[j]--;
                penalty -= i - j + 1;
                res--;
            }
        }
        cout << ans << endl;
    }

    return 0;
}