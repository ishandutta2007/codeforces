#include <bits/stdc++.h>

using namespace std;

const int N = 1.5E5, P = 998244353;

vector<int> e[N];

int n, q, Clock;
int Sum[N], Size[N], Top[N], In[N], Dep[N], Parent[N], Out[N];
int Fen[N + 1];

void Add(int x, int y) {
    while (x <= N) {
        Fen[x] = (Fen[x] + y) % P;
        x += x & -x;
    }
}

void Add(int l, int r, int x) {
    Add(l + 1, x);
    Add(r + 1, P - x);
}

int Get(int x) {
    ++x;
    int Res = 0;
    while (x > 0) {
        Res = (Res + Fen[x]) % P;
        x -= x & -x;
    }
    return Res;
}

int Pow(int Base, int Exp) {
    int Res = 1;
    while (Exp) {
        if (Exp & 1) Res = 1LL * Res * Base % P;
        Base = 1LL * Base * Base % P;
        Exp >>= 1;
    }
    return Res;
}

void DfsSz(int u) {
    Size[u] = 1;
    if (Parent[u] != -1) e[u].erase(find(e[u].begin(), e[u].end(), Parent[u]));
    for (int &v : e[u]) {
        Dep[v] = Dep[u] + 1;
        Parent[v] = u;
        DfsSz(v);
        Size[u] += Size[v];
        if (Size[v] > Size[e[u][0]]) swap(v, e[u][0]);
    }
}

void DfsHLD(int u) {
    In[u] = Clock++;
    for (int v : e[u]) {
        Top[v] = v == e[u][0] ? Top[u] : v;
        DfsHLD(v);
    }
    Out[u] = Clock;
}

void Modify(int v, int d) {
    Add(0, In[v], 1LL * d * Size[v] % P);
    Add(Out[v], n, 1LL * d * Size[v] % P);
    Add(In[v], In[v] + 1, 1LL * d * n % P);
    if (!e[v].empty()) {
        int u = e[v][0];
        Add(In[u], Out[u], 1LL * d * (n - Size[u]) % P);
    }
    Sum[v] = (Sum[v] + d) % P;
}

int Query(int v) {
    int Res = Get(In[v]);
    while (v != -1) {
        v = Top[v];
        if (Parent[v] != -1) Res = (Res + 1LL * Sum[Parent[v]] * (n - Size[v])) % P;
        v = Parent[v];
    }
    return Res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        e[--u].push_back(--v);
        e[v].push_back(u);
    }
    Parent[0] = -1;
    DfsSz(0);
    DfsHLD(0);
    int inv = Pow(n, P - 2);
    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int v, d;
            cin >> v >> d;
            Modify(--v, d);
        } else {
            int v;
            cin >> v;
            cout << 1LL * Query(--v) * inv % P << "\n";
        }
    }
    return 0;
}