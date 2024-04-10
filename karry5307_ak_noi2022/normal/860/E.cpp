#include<bits/stdc++.h>
using namespace std;
#define N 500101
int fi[N], tot;
struct edge {
    int nx, to;
}e[N*2];
void ps(int x, int y) {
    e[++tot] = (edge){ fi[x],y };
    fi[x] = tot;
}
vector<int>C[N], lk[N];
int Sz[N], d[N], sz[N];
#define LL long long
LL S[N];
namespace IMPACT {
    int f[N][30],cnt,dfn[N];
    void dfs(int x) {
        d[x] = d[f[x][0]] + 1;
        C[d[x]].push_back(x);
        dfn[x] = ++cnt;
        Sz[x] = 1;
        for (int i = 1;i <= 22;i++)f[x][i] = f[f[x][i - 1]][i - 1];
        for (int i = fi[x], y;(y = e[i].to);i = e[i].nx) {
            f[y][0] = x;
            dfs(y);
            Sz[x] += Sz[y];
        }
    }
    int lca(int x, int y) {
        if (d[x] < d[y])swap(x, y);
        for (int i = 22;i >= 0;i--) {
            if (d[f[x][i]] >= d[y])x = f[x][i];
        }
        if (x == y)return x;
        for (int i = 22;i >= 0;i--) {
            if (f[x][i] != f[y][i])x = f[x][i], y = f[y][i];
        }
        return f[x][0];
    }
    bool cmp(int x, int y) {
        return dfn[x] < dfn[y];
    }
    stack<int>st;
    void Ps(int x, int y) {
        // cout << x << y << endl;
        lk[x].push_back(y);
    }
    int build(vector<int>v) {
        sort(v.begin(), v.end(), cmp);
        // for (int x : v)cout << x << ' ';puts("");
        for (int x : v) {
            lk[x].clear();
            if (st.empty()) { st.push(x);continue; }
            int l = lca(x, st.top()), lt = 0;
            if (l == st.top()) { if(x!=l)st.push(x); continue; }
            while (st.size() && dfn[l] < dfn[st.top()]) {
                if (lt)Ps(st.top(), lt);
                lt = st.top();
                st.pop();
            }
            if (st.size()) {
                if (st.top() != l) {
                    lk[l].clear();
                    st.push(l);
                }
                Ps(l, lt);
            }
            else {
                lk[l].clear();
                st.push(l);
                Ps(l, lt);
            }
            st.push(x);
            // cout << "size:" << st.size()<<' '<<st.top() << endl;
        }
        int r = 0;
        while (st.size()) {
            if(r)Ps(st.top(), r);
            r = st.top();
            st.pop();
        }
        return r;
    }
}
using namespace IMPACT;
void DP1(int x) {
    if (lk[x].empty()) {
        sz[x] = 1;
        return;
    }
    sz[x] = 0;
    for (int y : lk[x]) {DP1(y);sz[x] += sz[y];}
    
}
void DP2(int x, LL g) {
    if (lk[x].empty()) {
        S[x] = g + (LL)d[x];
        //cout << x << ' ' << g << ' ' << d[x] << endl;
    }
    for (int y : lk[x]) { DP2(y, g + (LL)(sz[x] - sz[y]) * d[x]); }
    // lk[x].clear();
}
void DP3(int x) {
    for (int i = fi[x], y;(y = e[i].to);i = e[i].nx) { S[y] += S[x];DP3(y); }
}
void TEST() {
    while EOF{
        int x,y;
    cin >> x >> y;
    cout << lca(x, y) << endl;
    }
}
int main() {
    int n, s;
    scanf("%d", &n);
    for (int i = 1,p;i <= n;i++) {
        scanf("%d", &p);
        if (!p)s = i;
        else ps(p, i);
    }
    dfs(s);
    // TEST();
    for (int i = 1;i <= n;i++)if (C[i].size()) {
        // cout << i << endl;
        // for (int j = 1;j <= n;j++)lk[j].clear();
        int rt = build(C[i]);
        DP1(rt);
        DP2(rt, 0);
    }
    DP3(s);
    for (int i = 1;i <= n;i++)printf("%lld ", S[i]-(LL)d[i]);
}