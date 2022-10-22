#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll res;

const int N = 150000;

vector <int> graf[N+5];
bool erased[N+5];
int sz[N+5], val[N+5];

void dfs_size(int v, int p){
    sz[v] = 1;
    for(auto c : graf[v]){
        if(erased[c] || c == p) continue;
        dfs_size(c, v);
        sz[v] += sz[c];
    }
}

int find_centroid(int v, int p, int svi){
    for(auto c : graf[v]) if(!erased[c] && c != p && 2*sz[c] > svi) return find_centroid(c, v, svi);
    return v;
}

vector <tuple <ll, ll, ll>> vecp[N+5], vecs[N+5];
int tr;

void dfs_pref(int v, int p, ll resp, ll sum, ll cnt){
    sum += val[v];
    cnt++;
    resp += val[v]*cnt;
    vecp[tr].push_back({resp, sum, cnt});
    for(auto c : graf[v]) if(!erased[c] && c != p) dfs_pref(c, v, resp, sum, cnt);
}

void dfs_suf(int v, int p, ll resp, ll sum, ll cnt){
    sum += val[v];
    cnt++;
    resp += sum;
    vecs[tr].push_back({resp, sum, cnt});
    for(auto c : graf[v]) if(!erased[c] && c != p) dfs_suf(c, v, resp, sum, cnt);
}

ll qpoint[N+5];

map <ll, int> gde;
vector <ll> cmpr;

struct line{
    ll k, n;
    ll eval(ll x){ return k*x+n; }
} seg[4*N+5];

void init(int node, int l, int r){
    seg[node] = {0, 0};
    if(l == r) return;
    int mid = (l+r)/2;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
}

ll query(int node, int l, int r, int x){
    ll h = seg[node].eval(qpoint[x]);
    if(l == r) return h;
    int mid = (l+r)/2;
    if(x <= mid) return max(h, query(node*2, l, mid, x));
    return max(h, query(node*2+1, mid+1, r, x));
}

void upd(int node, int l, int r, line k){
    int mid = (l+r)/2;
    if(seg[node].eval(qpoint[mid]) < k.eval(qpoint[mid])) swap(seg[node], k);
    if(l == r) return;
    if(seg[node].eval(qpoint[l]) < k.eval(qpoint[l])) upd(node*2, l, mid, k);
    else upd(node*2+1, mid+1, r, k);
}

void decompose(){
    queue <int> q;
    q.push(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        dfs_size(v, 0);
        int sv = sz[v];
        v = find_centroid(v, 0, sv);
        tr = 0;
        for(auto c : graf[v]){
            if(erased[c]) continue;
            tr++;
            vecp[tr].clear();
            vecs[tr].clear();
            dfs_pref(c, v, val[v], val[v], 1);
            dfs_suf(c, v, 0, 0, 0);
        }
        gde.clear();
        cmpr.clear();
        for(int i=1; i<=tr; i++){
            for(auto c : vecp[i]) cmpr.push_back(get<1>(c));
            for(auto c : vecp[i]) res = max(res, get<0>(c));
            for(auto c : vecs[i]) res = max(res, get<0>(c) + val[v]*(get<2>(c) + 1));
        }
        sort(cmpr.begin(), cmpr.end());
        int tjd = 0;
        for(auto c : cmpr) gde[c] = ++tjd, qpoint[tjd] = c;
        init(1, 1, sv);
        for(int i=1; i<=tr; i++){
            for(auto c : vecp[i]) res = max(res, get<0>(c) + query(1, 1, sv, gde[get<1>(c)]));
            for(auto c : vecs[i]) upd(1, 1, sv, {get<2>(c), get<0>(c)});
        }
        init(1, 1, sv);
        for(int i=tr; i>=1; i--){
            for(auto c : vecp[i]) res = max(res, get<0>(c) + query(1, 1, sv, gde[get<1>(c)]));
            for(auto c : vecs[i]) upd(1, 1, sv, {get<2>(c), get<0>(c)});
        }
        erased[v] = 1;
        for(auto c : graf[v]) if(!erased[c]) q.push(c);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1; i<=n; i++) cin >> val[i];
    decompose();
    cout << res << "\n";
    return 0;
}