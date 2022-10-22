#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;
const int LOG = 18;

vector <pair <int, int>> graf[N+5];
int sz[N+5], A[N+5], B[N+5];
ll w[N+5];
bool erased[N+5];

void dfs_size(int v, int p){
    sz[v] = 1;
    for(auto pr : graf[v]){
        int c = pr.first;
        if(erased[c] || c == p) continue;
        dfs_size(c, v);
        sz[v] += sz[c];
    }
}

int find_centroid(int v, int p, int sve){ for(auto c : graf[v]) if(!erased[c.first] && c.first != p && 2*sz[c.first] > sve) return find_centroid(c.first, v, sve); return v; }

int in[LOG+1][N+5], out[LOG+1][N+5], par[LOG+1][N+5], kome[LOG+1][N+5];
ll niz[LOG+1][N+5];

int tjm[LOG+1];

struct Segment{
    ll val[4*N+5];
    ll lazy[4*N+5];
    void propagate(int node, int l, int r){
        val[node] += lazy[node];
        if(l == r){
            lazy[node] = 0;
            return;
        }
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
        lazy[node] = 0;
    }
    void init(int node, int l, int r, int lg){
        if(l == r){
            val[node] = niz[lg][l];
            return;
        }
        int mid = (l+r)/2;
        init(node*2, l, mid, lg);
        init(node*2+1, mid+1, r, lg);
        val[node] = max(val[node*2], val[node*2+1]);
    }
    void upd(int node, int l, int r, int tl, int tr, ll v){
        propagate(node, l, r);
        if(tl > r || l > tr) return;
        if(tl <= l && r <= tr){
            lazy[node] += v;
            propagate(node, l, r);
            return;
        }
        int mid = (l+r)/2;
        upd(node*2, l, mid, tl, tr, v);
        upd(node*2+1, mid+1, r, tl, tr, v);
        val[node] = max(val[node*2], val[node*2+1]);
    }
    ll query(int node, int l, int r, int tl, int tr){
        propagate(node, l, r);
        if(tl > r || l > tr) return 0;
        if(tl <= l && r <= tr) return val[node];
        int mid = (l+r)/2;
        return max(query(node*2, l, mid, tl, tr), query(node*2+1, mid+1, r, tl, tr));
    }
} seg[LOG+1];

void dfs_depth(int v, int p, ll d, int depth, int root){
    par[depth][v] = p;
    kome[depth][v] = root;
    for(auto pr : graf[v]){
        int c, dc;
        tie(c, dc) = pr;
        if(erased[c] || c == p) continue;
        dfs_depth(c, v, d + w[dc], depth, root);
        if(!in[depth][v]) in[depth][v] = in[depth][c];
        out[depth][v] = out[depth][c];
    }
    if(!in[depth][v]){
        in[depth][v] = out[depth][v] = ++tjm[depth];
        niz[depth][in[depth][v]] = d;
    }
}

int kd[N+5];

void decompose(){
    queue <pair <int, int>> q;
    q.push({1, 1});
    while(!q.empty()){
        int v, d;
        tie(v, d) = q.front();
        q.pop();
        dfs_size(v, 0);
        v = find_centroid(v, 0, sz[v]);
        kd[v] = d;
        for(auto c : graf[v]){
            if(erased[c.first]) continue;
            dfs_depth(c.first, v, w[c.second], d, c.first);
        }
        erased[v] = 1;
        for(auto c : graf[v]) if(!erased[c.first]) q.push({c.first, d + 1});
    }
}

priority_queue <pair <ll, int>> lengths[N+5];
priority_queue <pair <ll, int>> sol;

ll dole[LOG+1][N+5];

ll calc(int v){
    int lg = kd[v];
    while(!lengths[v].empty() && dole[lg][lengths[v].top().second] != lengths[v].top().first) lengths[v].pop();
    if(lengths[v].empty()) return 0;
    ll x;
    int c;
    tie(x, c) = lengths[v].top();
    lengths[v].pop();
    while(!lengths[v].empty() && (dole[lg][lengths[v].top().second] != lengths[v].top().first || lengths[v].top().second == c)) lengths[v].pop();
    if(lengths[v].empty()){
        lengths[v].push({x, c});
        return x;
    }
    ll y = lengths[v].top().first;
    lengths[v].push({x, c});
    return x + y;
}

ll rez[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, qrs;
    ll W;
    cin >> n >> qrs >> W;
    for(int i=1; i<n; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graf[a].push_back({b, i});
        graf[b].push_back({a, i});
        w[i] = c;
        A[i] = a;
        B[i] = b;
    }
    decompose();
    for(int i=1; i<=LOG; i++) if(tjm[i]) seg[i].init(1, 1, tjm[i], i);
    for(int v=1; v<=n; v++){
        int lg = kd[v];
        for(auto pr : graf[v]){
            int c = pr.first;
            if(kd[c] <= lg) continue;
            lengths[v].push({dole[lg][c] = seg[lg].query(1, 1, tjm[lg], in[lg][c], out[lg][c]), c});
        }
        sol.push({rez[v] = calc(v), v});
    }
    ll res = 0;
    while(qrs--){
        int edg;
        ll d;
        cin >> edg >> d;
        edg = 1 + (edg + res)%(n-1);
        d = (d + res)%W;
        int a = A[edg], b = B[edg];
        for(int lg=1; lg<=LOG; lg++){
            if(kd[a] < lg || kd[b] < lg) break;
            if(par[lg][a] == b) swap(a, b);
            int c = kome[lg][b];
            int v = par[lg][c];
            seg[lg].upd(1, 1, tjm[lg], in[lg][b], out[lg][b], d - w[edg]);
            lengths[v].push({dole[lg][c] = seg[lg].query(1, 1, tjm[lg], in[lg][c], out[lg][c]), c});
            sol.push({rez[v] = calc(v), v});
        }
        while(!sol.empty() && rez[sol.top().second] != sol.top().first) sol.pop();
        res = sol.top().first;
        w[edg] = d;
        cout << res << "\n";
    }
    return 0;
}