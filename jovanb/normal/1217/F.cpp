#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 400000;

struct DSU{
    int n;
    int par[MAXN+5];
    int rnk[MAXN+5];
    struct operacija{
        int a, b, rnka, rnkb;
    };
    stack <operacija> st;
    void init(int g){
        n = g;
        for(int i=1; i<=n; i++){
            par[i] = i;
            rnk[i] = 0;
        }
    }
    int root(int x){ return (par[x] == x ? x : root(par[x])); }
    void povezi(int a, int b){
        a = root(a);
        b = root(b);
        st.push({a, b, rnk[a], rnk[b]});
        if(a == b) return;
        if(rnk[a] < rnk[b]) swap(a, b);
        if(rnk[a] == rnk[b]) rnk[a]++;
        par[b] = a;
    }
    bool check(int a, int b){ return root(a) == root(b); }
    void rollback(){
        operacija g = st.top();
        st.pop();
        int a = g.a;
        int b = g.b;
        rnk[a] = g.rnka;
        rnk[b] = g.rnkb;
        par[a] = a;
        par[b] = b;
    }
} dsu;


map <pair <int, int>, int> koji;
int last;
bool enabled[MAXN+5];
int gde[MAXN+5];
int typ[MAXN+5];
int A[MAXN+5];
int B[MAXN+5];

vector <int> vec[MAXN+5];

vector <pair <int, int>> seg[4*MAXN+5];

int n, m;

void upd(int node, int l, int r, int tl, int tr, pair <int, int> gr){
    if(tl > tr || tl > r || l > tr) return;
    if(tl <= l && r <= tr){
        seg[node].push_back(gr);
        return;
    }
    int mid = (l+r)/2;
    upd(node*2, l, mid, tl, tr, gr);
    upd(node*2+1, mid+1, r, tl, tr, gr);
}

void dfs(int node, int l, int r){
    for(auto c : seg[node]) dsu.povezi(c.first, c.second);
    if(l == r){
        if(typ[l] == 1){
            int a, b;
            a = A[l], b = B[l];
            if(a > b) swap(a, b);
            int gr = koji[{a, b}];
            gde[gr]++;
            if(last == 0) enabled[gr] ^= 1;
            if(enabled[gr]) upd(1, 1, m, l+1, vec[gr][gde[gr]]-1, {a, b});
            a = a%n+1, b = b%n+1;
            if(a > b) swap(a, b);
            gr = koji[{a, b}];
            gde[gr]++;
            if(last == 1) enabled[gr] ^= 1;
            if(enabled[gr]) upd(1, 1, m, l+1, vec[gr][gde[gr]]-1, {a, b});
        }
        else cout << (last = dsu.check((A[l]+last-1)%n + 1, (B[l]+last-1)%n + 1));
        for(auto c : seg[node]) dsu.rollback();
        return;
    }
    int mid = (l+r)/2;
    dfs(node*2, l, mid);
    dfs(node*2+1, mid+1, r);
    for(auto c : seg[node]) dsu.rollback();
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> n >> m;
    int cnt = 0;
    dsu.init(n);
    for(int i=1; i<=m; i++){
        cin >> typ[i] >> A[i] >> B[i];
        if(typ[i] == 1){
            int a = A[i], b = B[i];
            if(a > b) swap(a, b);
            if(!koji[{a, b}]) koji[{a, b}] = ++cnt;
            vec[koji[{a, b}]].push_back(i);
            a = A[i]%n + 1;
            b = B[i]%n + 1;
            if(a > b) swap(a, b);
            if(!koji[{a, b}]) koji[{a, b}] = ++cnt;
            vec[koji[{a, b}]].push_back(i);
        }
    }
    for(int i=1; i<=cnt; i++) vec[i].push_back(m+1);
    dfs(1, 1, m);
    return 0;
}