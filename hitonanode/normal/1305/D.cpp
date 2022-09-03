#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int N;
vector<set<int>> to;
vector<int> par;

vector<int> ava;

void dfs(int now, int prv = -1) {
    par[now] = prv;
    for (auto nxt : to[now]) if (nxt != prv and ava[nxt])
    {
        dfs(nxt, now);
    }
}

void dfs_invalid(int now, int prv) {
    ava[now] = 0;
    for (auto nxt : to[now]) if (nxt != prv and ava[nxt]) {
        dfs_invalid(nxt, now);
    }
}

int main()
{
    cin >> N;
    to.resize(N + 1);
    REP(_, N - 1) {
        int u, v;
        cin >> u >> v;
        to[u].insert(v);
        to[v].insert(u);
    }
    par.resize(N + 1, -1);
    ava.resize(N + 1, 1);
    ava[0] = 0;
    while (accumulate(ava.begin(), ava.end(), 0) > 1)
    {
        vector<int> ord(N + 1);
        FOR(i, 1, N + 1) if (ava[i]) for (auto j : to[i]) ord[i] += ava[j];
        int a = 1;
        while (ord[a] != 1) a++;
        int b = a + 1;
        while (ord[b] != 1) b++;
        cout << "? " << a << " " << b << endl;
        cout.flush();
        int q;
        cin >> q;
        dfs(q, -1);
        if (a != q) {
            while (par[a] != q) a = par[a];
        }
        if (b != q) {
            while (par[b] != q) b = par[b];
        }
        if (q == a) dfs_invalid(b, q);
        else if (q == b) dfs_invalid(a, q);
        else {
            dfs_invalid(a, q);
            dfs_invalid(b, q);
        }
    }
    int ret = 0;
    while (!ava[ret]) ret++;
    cout << "! " << ret << endl;
}