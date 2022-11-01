#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = LLONG_MAX, MOD = 1e9+7;


struct BINARY{
    int n, LOGN=1;
    vvi g;
    vi depth;
    vvi anc, val;
    BINARY(vvi& _g, int s=0):g(_g), n(_g.size()){
        for(int i=1;i<=n;i<<=1,++LOGN);
        depth.resize(n,0);
        anc.resize(n,vi(LOGN,-1));
        val.resize(n,vi(LOGN,0));
        dfs(s);
    }
    void dfs(int cur, int p=-1,int d=0){
        anc[cur][0] = p;
        for(int i=1;anc[cur][i-1]!=-1;i++){
            anc[cur][i] = anc[anc[cur][i-1] ][i-1];
        }
        depth[cur] = d;
        for(auto nei:g[cur]){
            if (nei==p) continue;
            dfs(nei, cur, d+1);
        }
    }
    int lift(int& a, int d){
        int res=0;
        for(int i=LOGN-1;i>=0;--i){
            if (a==-1) return res;
            if (d>= 1<<i){
                d-=1<<i;
                res += 1<<i;
                a = anc[a][i];
            }
        }
        return res;
    }
    int query(int a,int b){
        if(depth[a]<depth[b]) swap(a,b);
        int res = lift(a, depth[a]-depth[b]);
        if (a==b) return a;
        for(int i=LOGN-1;i>=0;--i){
            if (anc[a][i]!=anc[b][i]){
                res += 2 * (1<<i);
                a=anc[a][i];
                b=anc[b][i];
            }
        }
        return anc[a][0];
    }
};
struct Node{
    int l=0, r=0;
    int val = 0;
};
const int MAX = 2e7;
Node tree[MAX]; int cnt = 1;
int getNode(){
    return cnt++;
}
void push(int c){
    if (!tree[c].l) tree[c].l = cnt++;
    if (!tree[c].r) tree[c].r = cnt++;
}
void pull(int c){
    tree[c].val = tree[tree[c].l].val ^ tree[tree[c].r].val;
}
int update(int i, int x, int c, int l, int r){
    int nc = cnt++;
    tree[nc] = tree[c];
    if (l==i && r==i+1){
        tree[nc].val ^= x;
        return nc;
    }
    int mid = (l+r)/2;
    if (i<mid) tree[nc].l = update(i,x,tree[nc].l, l, mid);
    else tree[nc].r = update(i,x,tree[nc].r, mid, r);
    pull(nc);
    return nc;
}
int query(int a, int b, int c, int l, int r){
    if (a>=r || b<=l) return 0;
    if (a<=l && r<=b) return tree[c].val;
    int v = 0, mid = (l+r)/2;
    if (tree[c].l) v^=query(a,b,tree[c].l,l,mid);
    if (tree[c].r) v^=query(a,b,tree[c].r,mid,r);
    return v;
}
int ll, rr;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto udist = uniform_int_distribution<int>(0, ((int(1)<<62)-1)*2+1);
int mrand(){
    return udist(rng);
}
int n,q;
vi a;
vvi g;
vi f;
vi h;
vi segs;
void dfs(int cur, int seg, int p=-1){
    f[cur] = p;
    segs[cur] = update(a[cur], h[a[cur]], seg, 0, n);
    for(int nei:g[cur]) if(nei!=p) dfs(nei, segs[cur], cur);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    a.resize(n); 
    loop(i,0,n) cin>>a[i], a[i]--;
    g.resize(n);
    loop(i,0,n-1){
        int a,b; cin>>a>>b; 
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    BINARY bin(g);
    h.resize(n);
    loop(i,0,n) h[i] = mrand();
    f.resize(n);
    segs.resize(n);
    dfs(0, 0);
    loop(i,0,q){
        int u,v,l,r; cin>>u>>v>>l>>r;
        u--, v--, l--, r--;
        int w = bin.query(u, v);
        int s1 = segs[u], s2 = segs[v], s3 = segs[w], s4 = (f[w]==-1?0:segs[f[w]]);
        auto getVS = [&](vi& ss){
            int res = 0;
            for(int s:ss) res^=tree[s].val;
            return res;
        };
        auto clean = [](vi& v){
            vi a;
            for(int s:v) if(s) a.pb(s);
            v = a;
        };
        vi ss = {s1, s2, s3, s4};
        int base = 0;
        if (l) for(int s:ss) base^=query(0,l,s,0,n);
        int a = 0, b = n;
        while(a+1<b){
            clean(ss);
            int mid = (a+b)/2;
            vi ls, rs;
            for(int s:ss) ls.pb(tree[s].l), rs.pb(tree[s].r);
            int vv = getVS(ls);
            if (l<mid && vv!=base) ss = ls, b = mid;
            else ss = rs, a = mid, base^=vv;
        }
        if (a<=r && base!=getVS(ss)) cout<<a+1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
6 8
3 2 1 3 1 3
1 2
1 3
2 4
2 5
4 6
3 5 1 1
3 5 1 3
3 5 3 3
1 1 2 2
1 1 3 3
1 4 1 5
1 6 1 3
1 6 3 3


*/