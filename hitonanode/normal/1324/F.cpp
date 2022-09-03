#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;
vector<vector<int>> to;

vector<int> dp1;
int dfs1(int now, int par)
{
    int score = A[now];
    for (auto nxt : to[now]) if (nxt != par) score += max(dfs1(nxt, now), 0);
    return dp1[now] = score;
}
vector<int> ret;
void dfs2(int now, int par, int add)
{
    int score = max(add, 0) + A[now];
    for (auto nxt : to[now]) if (nxt != par) {
        score += max(dp1[nxt], 0);
    }
    ret[now] = score;
    for (auto nxt : to[now]) if (nxt != par) {
        dfs2(nxt, now, score - max(dp1[nxt], 0));
    }
}

int main()
{
    cin >> N;
    A.resize(N);
    for (auto &x : A) {
        cin >> x;
        x = x * 2 - 1;
    }

    to.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    dp1.resize(N);
    dfs1(0, -1);

    ret.resize(N);
    dfs2(0, -1, 0);
    for (auto x : ret) printf("%d ", x);
    puts("");
}