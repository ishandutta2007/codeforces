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

const int maxn = 1 << 15;
const int inf = 1e9;

int n;
int a[maxn];
int mx[maxn];
vector<int> e[maxn];
void dfs1(int v) {
    int curmx = 0;
    for (int i = 0; i < (int)e[v].size(); i++) {
        dfs1(e[v][i]);
        curmx = max(curmx, mx[e[v][i]]);
    }
    curmx += a[v];
    mx[v] = curmx;
}

int newmx;
int cans;
void dfs2(int v, int cursum) {
    int added = 0;
    if (mx[v] + cursum < newmx) {
        cans += newmx - mx[v] - cursum;
        added += newmx - mx[v] - cursum;
    }
    for (int i = 0; i < (int)e[v].size(); i++) dfs2(e[v][i], cursum + a[v] + added);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//ios_base::sync_with_stdio(0);

    while (cin >> n) {
        int cmx = (1 << (n + 1)) - 2 + 1;
        for (int i = 0; i < (1 << (n + 1)) - 2; i++) cin >> a[i + 2];

        for (int i = 1; i <= cmx; i++) e[i].clear();
        for (int i = 2; i <= cmx; i++) e[i / 2].push_back(i);

        dfs1(1);
        int ans = 1e9;
        for (newmx = mx[1]; newmx <= 3333; newmx++) {
            cans = 0;
            dfs2(1, 0);
            ans = min(ans, cans);
        }
        cout << ans << endl;
    }

	return 0;
}