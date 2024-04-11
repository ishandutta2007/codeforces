#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 5;
const int maxk = 10;

int n, k;
vector<int> graph[maxn];
int size[maxn];
int sumdist[maxn];
int sumback[maxn];
int cnt[maxn][maxk];
int cntback[maxn][maxk];
int ans = 0;

void dfs1(int v, int p) {
    size[v] = 1;
    for (auto u: graph[v]) {
        if (u != p) {
            dfs1(u, v);
            size[v] += size[u];
            sumdist[v] += sumdist[u];
        }
    }
    sumdist[v] += size[v] - 1;
}

void dfs2(int v, int p) {
    if (p != -1) {
        sumback[v] = sumback[p] + (n - size[v]);
        sumback[v] += sumdist[p] - sumdist[v] - size[v];
    }
    for (auto u: graph[v]) {
        if (u != p) {
            dfs2(u, v);
        }
    }
}

void dfs3(int v, int p) {
    cnt[v][0] = 1;
    for (auto u: graph[v]) {
        if (u != p) {
            dfs3(u, v);
            for (int i = 0; i < k; ++i) {
                cnt[v][i] += cnt[u][(i + k - 1) % k];
            }
        }
    }
}

void dfs4(int v, int p) {
    if (p != -1) {
        for (int i = 0; i < k; ++i) {
            int t = (i + k - 1) % k;
            int nxt = (i + k - 2) % k;
            cntback[v][i] += cntback[p][t];
            cntback[v][i] += cnt[p][t] - cnt[v][nxt];
        }
    }
    for (auto u: graph[v]) {
        if (u != p) {
            dfs4(u, v);
        }
    }
}

void dfs5(int v, int p) {
    for (auto u: graph[v]) {
        if (u != p) {
            dfs5(u, v);
        }
    }
    int tmp = sumdist[v] + sumback[v];
    for (int i = 1; i < k; ++i) {
        tmp += (k - i) * (cnt[v][i] + cntback[v][i]);
        /*if (cnt[v][i] + cntback[v][i])
            cerr << v + 1 << ' ' << i << ' ' << ' ' << cnt[v][i] << ' ' << cntback[v][i] << endl;*/
    }
    ans += tmp / k;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs1(0, -1);
    dfs2(0, -1);
    dfs3(0, -1);
    dfs4(0, -1);
    dfs5(0, -1);
    cout << ans / 2 << '\n';
}