#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 1e5 + 5;

vector <pii> ans;
set <int> son[N];
vector <int> adj[N], po[N];
set <pii> can[N], subsiz;
set <pii> :: iterator it;
int siz[N], maxn[N], dep[N], fa[N], used[N];
int n, rt, tot; long long k, nowans;

void getroot(int u, int fa) {
    siz[u] = 1;
    for (auto v : adj[u]) {
        if (v == fa) continue;
        getroot(v, u);
        maxn[u] = max(maxn[u], siz[v]);
        siz[u] += siz[v];
    }
    maxn[u] = max(maxn[u], n - siz[u]);
    // fprintf(stderr, "u = %d, maxn[u] = %d\n", u, maxn[u]);
    if (maxn[u] < maxn[rt]) rt = u;
}

void dfs1(int u) {
    siz[u] = 1;
    for (auto v : adj[u]) {
        if (v == fa[u]) continue;
        son[u].insert(v);
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
        siz[u] += siz[v];
    }
}

void dfs2(int u, int id) {
    if (son[u].size() != 0) can[id].insert(make_pair(dep[u], u));
    for (auto v : adj[u]) {
        if (v == fa[u]) continue;
        dfs2(v, id);
    }
}

void dfs3(int u, int id) {
    if (!used[u]) po[id].push_back(u);
    for (auto v : adj[u]) {
        if (v == fa[u]) continue;
        dfs3(v, id);
    }
}

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    maxn[0] = n + 1; rt = 0; getroot(1, 0); dfs1(rt);
    for (int i = 1; i <= n; i++) nowans += dep[i];
    if ((nowans & 1) != (k & 1)) {
        printf("NO\n");
        return 0;
    }
    for (auto v : adj[rt]) {
        dfs2(v, v);
        subsiz.insert(make_pair(siz[v], v));
    }
    while (nowans > k) {
        it = subsiz.end(); --it;
        // cout << it -> first << endl;
        if (it -> first < 2) break;
        int newsiz = it -> first - 2, id = it -> second;
        subsiz.erase(it); subsiz.insert(make_pair(newsiz, id));
        it = can[id].end(); --it;
        int maxdep = it -> first, canid = it -> second;
        if (nowans - maxdep * 2 >= k) {
            nowans -= maxdep * 2;
            int ansu = *son[canid].begin(), ansv;
            son[canid].erase(son[canid].begin());
            if (son[canid].size() != 0) {
                ansv = *son[canid].begin();
                son[canid].erase(son[canid].begin());
            } else {
                ansv = canid;
                son[fa[canid]].erase(son[fa[canid]].find(canid));
            }
            if (son[canid].size() == 0) can[id].erase(it);
            if (canid != id && son[fa[canid]].size() == 0) can[id].erase(can[id].find(make_pair(dep[fa[canid]], fa[canid])));
            ans.push_back(make_pair(ansu, ansv)); used[ansu] = used[ansv] = 1;
        } else {
            for (it = can[id].begin(); it != can[id].end(); ++it) {
                if (it -> first == (nowans - k) / 2) {
                    int ansu = it -> second;
                    int ansv = *son[it -> second].begin();
                    ans.push_back(make_pair(ansu, ansv)); used[ansu] = used[ansv] = 1;
                    break;
                }
            }
            nowans = k;
            break;
        }
    }
    if (nowans != k) {
        printf("NO\n");
        return 0;
    }
    subsiz.clear();
    tot = 1; po[1].push_back(rt); subsiz.insert(make_pair(1, 1));
    for (auto v : adj[rt]) {
        ++tot;
        dfs3(v, tot);
        subsiz.insert(make_pair(po[tot].size(), tot));
    }
    while (1) {
        auto it1 = subsiz.end(); --it1;
        if (it1 -> first == 0) break;
        auto it2 = it1; --it2;
        int id1 = it1 -> second, id2 = it2 -> second;
        subsiz.erase(it1); subsiz.erase(it2);
        ans.push_back(make_pair(po[id1].back(), po[id2].back()));
        po[id1].pop_back(); po[id2].pop_back();
        subsiz.insert(make_pair(po[id1].size(), id1));
        subsiz.insert(make_pair(po[id2].size(), id2));
    }
    printf("YES\n");
    for (auto it : ans) printf("%d %d\n", it.first, it.second);
    return 0;
}