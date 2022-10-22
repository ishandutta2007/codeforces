#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

set <pair <int, int>> q;

const int MAXN = 300000;

int kor[MAXN+5];
vector <int> g1[MAXN+5];
vector <int> g2[MAXN+5];
int in[MAXN+5];
int out[MAXN+5];

int res;
int trr;

int seg[8*MAXN+5];

void init(int node, int l, int r){
    seg[node] = 0;
    if(l == r) return;
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
}

int query(int node, int l, int r, int tl, int tr){
    if(tl > r || l > tr) return 0;
    if(tl <= l && r <= tr){
        return seg[node];
    }
    int mid = (l+r)/2;
    int a = query(node*2, l, mid, tl, tr);
    int b = query(node*2+1, mid+1, r, tl, tr);
    if(in[a] >= in[b]) return a;
    return b;
}

void upd(int node, int l, int r, int x, int val){
    if(l == r){
        seg[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid){
        upd(node*2, l, mid, x, val);
    }
    else upd(node*2+1, mid+1, r, x, val);
    if(in[seg[node*2]] >= in[seg[node*2+1]]) seg[node] = seg[node*2];
    else seg[node] = seg[node*2+1];
    //if(x == 1) cout << seg[node*2] << seg[node*2+1] << "asdasfasf" << endl;
}

int n;

int chroot[MAXN+5];
int prr[MAXN+5];

int findparent(int v){
    //return query(1, 1, 2*n, in[v], 2*n);
    int k = prr[v];
    while(k){
        int x = chroot[k];
        int g = query(1, 1, 2*n, in[x], in[k]);
        if(g){
            return g;
        }
        k = prr[x];
    }
    return 0;
}

void dodaj(int v){
    int par = findparent(v);
    upd(1, 1, 2*n, in[v], v);
    q.insert({in[v], v});
    //cout << "Dodajem " << v << endl;
    if(kor[par]){
        kor[par] = 0;
        kor[v] = 1;
        //cout << "Ne koristim vise " << par << endl;
        //cout << "Koristim " << v << endl;
        return;
    }
    auto c = q.lower_bound({in[v]+1, -1});
    if(c == q.end() || (c->first > out[v])){
        //cout << "Koristim " << v << endl;
        kor[v] = 1;
        trr++;
        return;
    }
}

void brisi(int v){
    upd(1, 1, 2*n, in[v], 0);
    q.erase({in[v], v});
    if(!kor[v]) return;
    kor[v] = 0;
    trr--;
    //cout << "Ne koristim vise " << v << endl;
    int par = findparent(v);
    if(!par) return;
    auto c = q.lower_bound({in[par]+1, -1});
    if(c == q.end() || (c->first > out[par])){
        kor[par] = 1;
        trr++;
        //cout << "Koristim " << par << endl;
        return;
    }
}

void dfs1(int v){
    dodaj(v);
    res = max(res, trr);
    //cout << v << " " << trr << endl;
    for(auto c : g1[v]) dfs1(c);
    brisi(v);
}

int tjm;

int sz[MAXN+5];

void dfs2(int v){
    in[v] = ++tjm;
    if(g2[v].empty()){
        out[v] = ++tjm;
        return;
    }
    int mxx = 0;
    for(auto c : g2[v]){
        if(sz[c] > sz[mxx]) mxx = c;
    }
    chroot[mxx] = chroot[v];
    dfs2(mxx);
    for(auto c : g2[v]){
        if(c == mxx) continue;
        chroot[c] = c;
        dfs2(c);
    }
    out[v] = ++tjm;
}

void dfs_sz(int v){
    sz[v] = 1;
    for(auto c : g2[v]){
        dfs_sz(c);
        sz[v] += sz[c];
    }
}

void solve(){
    cin >> n;
    res = 0;
    init(1, 1, 2*n);
    trr = 0;
    for(int i=1; i<=n; i++){
        kor[i] = 0;
        g1[i].clear();
        g2[i].clear();
    }
    for(int i=2; i<=n; i++){
        int x;
        cin >> x;
        g1[x].push_back(i);
    }
    for(int i=2; i<=n; i++){
        int x;
        cin >> x;
        prr[i] = x;
        g2[x].push_back(i);
    }
    tjm = 0;
    dfs_sz(1);
    chroot[1] = 1;
    dfs2(1);
    dfs1(1);
    //cout << chroot[2] << "XD " << endl;
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
9
1 2 2 2 5 4 5 3
1 2 3 4 4 2 4 8
*/