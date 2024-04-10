/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option
 
#include<bits/stdc++.h>
using namespace std;
 
// #define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define iii pair<int, ii>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int b[maxN];
 
int tree[maxN * 4];
int l[maxN * 4];
int r[maxN * 4];
 
inline void redate(int node){
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
 
void build(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    if(left == right){
        tree[node] = b[left];
        return;
    }
    int mid = (left + right) / 2;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
    redate(node);
}
 
int god;
 
set<ii> st;
vector<ii> temp;
map<ii, int> mp;
ii pr[maxN * 2];
int imp[maxN * 2];
int m;
 
int type[maxN * 3];
int vl[maxN * 3];
 
int par[maxN];
int find(int i){
    if(i == par[i]) return i;
    else return par[i] = find(par[i]);
}
 
bool unite(int i, int j){
    i = find(i); j = find(j);
    if(i == j) return 0;
    par[i] = j; return 1;
}
 
bool used[maxN];
vector<ii> vc[maxN];
int in[maxN];
int cnt = 0;
set<int> inter;
int pinfinder[maxN * 3];
 
void take(int node, int left, int right){
    if(left > right) return;
    if(left == l[node] && right == r[node]){
        if(tree[node] > tree[god]) god = node; return;
    }
    int mid = r[node * 2];
    take(node * 2, left, min(mid, right));
    take(node * 2 + 1, max(left, mid + 1), right);
}
 
void killdown(int node){
    if(l[node] == r[node]){
        cout << tree[node] << endl;
        tree[node] = 0; return;
    }
    if(tree[node * 2] > tree[node * 2 + 1]) killdown(node * 2);
    else killdown(node * 2 + 1);
    redate(node);
}
 
signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> n >> m >> o;
    memset(imp, 0, sizeof(imp));
    for1(i, 1, n){
        cin >> a[i];
        par[i] = i;
    }
    for1(i, 1, m){
        cin >> pr[i].fi >> pr[i].se;
        st.insert(pr[i]);
    }
    for1(i, 1, o){
        cin >> type[i] >> vl[i];
        if(type[i] == 2) st.erase(pr[vl[i]]);
    }
    for(ii orc : st) temp.pb(orc); st.clear();
    for(ii pp : temp){
        if(unite(pp.fi, pp.se)) st.insert(pp);
    } x = 0; temp.clear(); for2(i, o, 1){
        if(type[i] == 2){
            int id = vl[i];
            if(unite(pr[id].fi, pr[id].se)){
                st.insert(pr[id]);
                mp[pr[id]] = ++x;
            }
        }
    }
    for1(i, 1, m){
        if(st.find(pr[i]) == st.end()) imp[i] = -1;
        else{
            imp[i] = mp[pr[i]];
            vc[pr[i].fi].pb(ii(imp[i], pr[i].se));
            vc[pr[i].se].pb(ii(imp[i], pr[i].fi));
        }
    }
    memset(used, 0, sizeof(used));
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    inter.insert(n + 1);
    for1(root, 1, n){
        if(!used[root]){
            int le = cnt + 1;
            inter.insert(le);
            pq.push(ii(0, root));
            while(!pq.empty()){
                ii pp = pq.top(); pq.pop();
                int node = pp.se;
                in[node] = ++cnt;
                used[node] = 1;
                if(cnt != le) pinfinder[pp.fi] = cnt;
                for(ii cc : vc[node]){
                    if(!used[cc.se]) pq.push(cc);
                }
            }
        }
    }
 
    tree[0] = -1;
    for1(i, 1, n){
        b[in[i]] = a[i];
    }
    build(1, 1, n);
    for1(i, 1, o){
        x = vl[i];
        if(type[i] == 2){
            if(imp[x] == -1) continue;
            assert(imp[x] != 0);
            x = pinfinder[imp[x]];
            inter.insert(x);
        }
        else{
            auto itr = inter.upper_bound(in[x]);
            y = (*itr) - 1;
            x = *(--itr);
            god = 0;
            assert(x <= y);
            take(1, x, y);
            killdown(god);
        }
    }
}