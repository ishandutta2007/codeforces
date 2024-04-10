#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300000;

typedef long long ll;

struct DSU{
    int n;
    ll res = 0;
    int par[2*MAXN+5];
    int x[2*MAXN+5];
    int y[2*MAXN+5];
    int rnk[2*MAXN+5];
    struct operacija{
        int a, b, rnka, rnkb, xa, xb, ya, yb;
    };
    stack <operacija> ops;
    void init(){
        for(int i=1; i<=2*n; i++) par[i] = i;
        for(int i=1; i<=n; i++) x[i] = 1;
        for(int i=n+1; i<=2*n; i++) y[i] = 1;
    }
    int root(int x){
        return x == par[x] ? x : root(par[x]);
    }
    void dodaj(int a, int b){
        int a1 = root(a);
        int b1 = root(b);
        if(a1 == b1){
            ops.push({0, 0, 0, 0, 0, 0, 0, 0});
            return;
        }
        if(rnk[a1] < rnk[b1]) swap(a1, b1);
        ops.push({a1, b1, rnk[a1], rnk[b1], x[a1], x[b1], y[a1], y[b1]});
        res -= 1LL*x[a1]*y[a1];
        res -= 1LL*x[b1]*y[b1];
        x[a1] += x[b1];
        x[b1] = 0;
        y[a1] += y[b1];
        y[b1] = 0;
        res += 1LL*x[a1]*y[a1];
        if(rnk[a1] == rnk[b1]) rnk[a1]++;
        par[b1] = a1;
    }
    void brisi(){
        operacija op = ops.top();
        ops.pop();
        int a = op.a;
        int b = op.b;
        res -= 1LL*x[a]*y[a];
        rnk[a] = op.rnka;
        rnk[b] = op.rnkb;
        par[a] = a;
        par[b] = b;
        x[a] = op.xa;
        y[a] = op.ya;
        x[b] = op.xb;
        y[b] = op.yb;
        res += 1LL*x[a]*y[a];
        res += 1LL*x[b]*y[b];
    }
} dsu;

int qa[MAXN+5];
int qb[MAXN+5];

map <pair <int, int>, int> posl;

vector <pair <int, int>> seg[4*MAXN+5];

void dodaj(int node, int l, int r, int tl, int tr, int a, int b){
    if(tl > r || l > tr) return;
    if(tl <= l && r <= tr){
        seg[node].push_back({a, b});
        return;
    }
    int mid = (l+r)/2;
    dodaj(node*2, l, mid, tl, tr, a, b);
    dodaj(node*2+1, mid+1, r, tl, tr, a, b);
}

void dfs(int node, int l, int r){
    for(auto c : seg[node]) dsu.dodaj(c.first, c.second);
    if(l == r){
        cout << dsu.res << " ";
        for(auto c : seg[node]) dsu.brisi();
        return;
    }
    int mid = (l+r)/2;
    dfs(node*2, l, mid);
    dfs(node*2+1, mid+1, r);
    for(auto c : seg[node]) dsu.brisi();
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    dsu.n = MAXN;
    dsu.init();
    int q;
    cin >> q;
    for(int i=1; i<=q; i++){
        cin >> qa[i] >> qb[i];
        qb[i] += MAXN;
        if(posl[{qa[i], qb[i]}]){
            dodaj(1, 1, q, posl[{qa[i], qb[i]}], i-1, qa[i], qb[i]);
            posl[{qa[i], qb[i]}] = 0;
        }
        else posl[{qa[i], qb[i]}] = i;
    }
    for(auto c : posl){
        if(c.second != 0) dodaj(1, 1, q, c.second, q, c.first.first, c.first.second);
    }
    dfs(1, 1, q);
    return 0;
}