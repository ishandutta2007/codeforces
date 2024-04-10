#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;
int n, m, S, T;
int dis[mxn], rdis[mxn], prv[mxn], prc[mxn];
vector <pair <int, int> > g[mxn];

void bfs_0(int S, vector <int> &vec) {
    queue <int> que;
    que.push(S);
    memset(dis, -1, sizeof(dis));
    dis[S] = 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        vec.pb(u);
        rep(i, g[u].size()) {
            int v = g[u][i].first;
            int c = g[u][i].second;
            if (c == 0 && !~dis[v]) {
                que.push(v);
                dis[v] = dis[u] + 1;
                prv[v] = u;
                prc[v] = 0;
            }
        }
    }
}

void bfs(vector <int> &nw) {
    queue <vector <int> > que;
    que.push(nw);
    while (!que.empty()) {
        nw = que.front();
        que.pop();
        rep(c0, 10) {
            vector <int> nex;
            rep(i, nw.size()) {
                int u = nw[i];
                rep(j, g[u].size()) {
                    int v = g[u][j].first;
                    int c = g[u][j].second;
                    if (c == c0 && !~dis[v]) {
                        nex.pb(v);
                        dis[v] = dis[u] + 1;
                        prv[v] = u;
                        prc[v] = c;
                    }
                }
            }
            if (!nex.empty()) que.push(nex);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    S = 0, T = n - 1;
    rep(i, m) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }
    vector <int> vec;
    bfs_0(T, vec);
    bfs(vec);
    string ans;
    for (int u = S; u != T; u = prv[u]) ans += char('0' + prc[u]);
    while (ans.back() == '0') ans.pop_back();
    if (ans.empty()) ans = "0";
    reverse(ans.begin(), ans.end());
    puts(ans.c_str());
    vector <int> path;
    for (int u = S; u != T; u = prv[u]) path.pb(u);
    path.pb(T);
    printf("%d\n", (int) path.size());
    rep(i, path.size()) printf("%d%c", path[i], " \n"[i + 1 == (int) path.size()]);
    return 0;
}