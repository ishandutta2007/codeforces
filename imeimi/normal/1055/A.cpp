#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, s;
vector<int> edge[1005];

int vis[1005];
void dfs(int x) {
    vis[x] = 1;
    for (int i : edge[x]) {
        if (vis[i]) continue;
        dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    vector<int> F;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (!x) continue;
        for (int j : F) edge[j].push_back(i);
        F.push_back(i);
    }
    vector<int> S;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (!x) continue;
        for (int j : S) edge[i].push_back(j);
        S.push_back(i);
    }
    dfs(1);
    printf(vis[s] ? "YES" : "NO");
    return 0;
}