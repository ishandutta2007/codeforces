#include <iostream>
#include <assert.h>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;

template <typename T>
T next_int() {
	T ans = 0, x = 1;
	char ch;
	do { ch = getchar(); } while (ch <= ' ') ;
	if(ch == '-') {
		x = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		ans = ans * 10 + (ch - '0');
		ch = getchar();
	}
	return ans * x;
}

#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

const int inf = 1e9, base = 1e9 + 7;
const int maxn = 1e5 + 500;
const ll llinf = 1e18;

vector<int> g[maxn], srt;
int used[maxn];

map<pair<int, int>, int> edge;

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
    srt.pb(v);
}

int main() {
    //freopen(".out", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--, y--;

        g[x].pb(y);
        edge[mp(x, y)] = i + 1;
    }

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(i);
    reverse(srt.begin(), srt.end());

    int ans = 0;
    for (int i = 0; i + 1 < srt.size(); i++) {
        if (!edge.count(mp(srt[i], srt[i + 1])))
            return cout << -1, 0;
        ans = max(ans, edge[mp(srt[i], srt[i + 1])]);
    }
    cout << ans;
    return 0;
}