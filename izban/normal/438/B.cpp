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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
vector<int> e[maxn];
int p[maxn], a[maxn], f[maxn];
int pr[maxn], cnt[maxn];

bool cmp(int i, int j) {
    return a[i] > a[j];
}

int get(int x) {
    if (pr[x] == x) return x;
    return pr[x] = get(pr[x]);
}

void Union(int u, int v) {
    if (cnt[u] < cnt[v]) swap(u, v);
    pr[v] = u;
    cnt[u] += cnt[v];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif


    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            e[i].clear();
            p[i] = i;
            pr[i] = i;
            cnt[i] = 1;
            f[i] = 0;
        }
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        sort(p + 1, p + 1 + n, cmp);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < e[p[i]].size(); j++) {
                int v = p[i];
                v = get(v);
                int to = e[p[i]][j];
                if (!f[to]) continue;
                to = get(to);
                if (v == to) continue;
                ans += 2LL * cnt[v] * cnt[to] * a[p[i]];
                Union(v, to);
            }
            f[p[i]] = 1;
        }
        printf("%.10lf\n", ans / (double) n / (n - 1));
    }

	return 0;
}