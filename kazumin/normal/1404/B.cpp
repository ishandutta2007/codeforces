#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int n, pa, pb, da, db, dist[MN], dist1[MN], p1, p2;
vector<int> a[MN];

void dfs(int cur, int par, int d) {
    dist[cur] = d;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur, d + 1);
    }
}

void dfs1(int cur, int par, int d) {
    dist1[cur] = d;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs1(nxt, cur, d + 1);
    }
}

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> pa >> pb >> da >> db;
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        int mx = 0, rad = 0x3f3f3f3f;
        if (da * 2 >= db) {printf("Alice\n"); goto clr;} //this is definitely correct
        dfs(pa, 0, 0);
        if (dist[pb] <= da) {printf("Alice\n"); goto clr;} //this is also definitely correct

        for (int i = 1; i <= n; i++) {
            if (dist[i] > mx) mx = dist[i], p1 = i;
        }
        dfs(p1, 0, 0);
        mx = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] > mx) mx = dist[i], p2 = i;
        }
        dfs1(p2, 0, 0);
        for (int i = 1; i <= n; i++) {
            rad = min(rad, max(dist1[i], dist[i]));
        }
        if (da >= rad) printf("Alice\n");
        else printf("Bob\n");

        clr: for (int i = 1; i <= n; i++) {
            a[i].clear();
            dist[i] = 0;
            dist1[i] = 0;
        }
    }

    return 0;
}