#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#define fs first
#define se second

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n, k;
vector<int> edge[200001];
vector<int> redge[200001];

void add_edge(int x, int y) {
    edge[x].push_back(y);
    redge[y].push_back(x);
}

bool vis[200001];
int scc[200001];
vector<int> st;
void dfs1(int x) {
    vis[x] = 1;
    for (int i : edge[x]) {
        if (vis[i]) continue;
        dfs1(i);
    }
    st.push_back(x);
}

void dfs2(int x, int c) {
    scc[x] = c;
    for (int i : redge[x]) {
        if (scc[i]) continue;
        dfs2(i, c);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int p;
    cin >> n >> k;
    cin >> p;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        add_edge(p, x);
        p = x;
    }
    cin >> p;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        add_edge(p, x);
        p = x;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        dfs1(i);
    }
    int m = 0;
    for (int i = n; i--; ) {
        if (scc[st[i]]) continue;
        dfs2(st[i], ++m);
    }
    if (m < k) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i) {
        printf("%c", 'a' + min(scc[i] - 1, 25));
    }
    return 0;
}