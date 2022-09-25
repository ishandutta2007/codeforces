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

const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
int a[maxn], p[maxn], f[maxn];
vector<int> e[maxn];

bool cmp(int i, int j) {
    return a[i] > a[j];
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
            f[i] = 0;
        }
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        sort(p + 1, p + n + 1, cmp);
        
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (int)e[p[i]].size(); j++) {
                if (!f[e[p[i]][j]]) {
                    ans += a[e[p[i]][j]];
                }
            }
            f[p[i]] = 1;
        }
        cout << ans << endl;
    }

	return 0;
}