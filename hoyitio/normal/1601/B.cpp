#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(a) a.begin(),a.end()
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 5e5+5;
#define P pair<int,int>
vector<P> g[maxn<<2];
int id[maxn<<2];
int le[maxn<<2];
int be[maxn*4];
void build(int rt, int l, int r){
    if(l == r){
        id[l] = rt;
        le[rt] = 1; be[rt] = l; return;
    }
    build(lson); build(rson);
    g[rt].pb(P(rt<<1, 0));
    g[rt].pb(P(rt<<1|1, 0));
    return;
}
void add(int rt, int l, int r, int L, int R, int u){
    if(L <= l && r <= R){
//        cout<<"u:"<<u<<" rt:"<<rt<<endl;
        g[u].pb(P(rt, 1)); return;
    }
    if(L <= mid) add(lson, L, R, u);
    if(R > mid) add(rson, L, R, u);
    return;
}
int n;
int a[maxn], b[maxn];
int dis[maxn<<4], pre[maxn<<4];

int q[maxn*40], head = 0, tail = 0;
int vis[maxn<<4];
const int inf = 0x3f3f3f3f;
int main(){
    scanf("%d", &n);
    fors(i,1,n+1) scanf("%d", &a[i]);
    fors(i,1,n+1) scanf("%d", &b[i]);
    build(1, 0, n);
    int tot = 0;
    for(int i = 0; i <= n; ++i) tot = max(tot, id[i]);

    for(int i = 1; i <= n; ++i){
        int l = i-a[i], r = i-1;
        if(l <= r) add(1, 0, n, l, r, tot+i);

        g[id[i]].pb(P( tot + i+b[i],0));

//        g[ id[i] ].pb( P(tot+i, 0) );
        be[tot+i] = i;

//        cout<<"i:"<<i<<" id:"<<id[i]<<" id2:"<<tot+i<<endl;
    }
    memset(dis, 0x3f, sizeof dis);

    head = tail = maxn*20;
    q[tail++] = id[n]; dis[ id[n] ] = 0;
    while(head < tail){
        int u = q[head++];
        if(vis[u]) continue;//
        vis[u] = 1;
        for(P p:g[u]){
            int v,w; tie(v,w) = p;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                if(w) q[tail++] = v;
                else q[--head] = v;
                pre[v] = u;
            }
        }
    }
//    cout<<"tot:"<<tot<<endl;
//    cout<<"?"<<endl;
    if(dis[id[0]] == inf){
        puts("-1");
    }else{
//        cout<<"dis:"<<dis[id[0]]<<endl;
        vector<int> ans;
        int cur = id[0]; ans.pb(0);
        while(cur != id[n]){
//            cout<<"cur:"<<cur<<endl;
            int nxt = pre[cur];
//            cout<<"nxt:"<<nxt<<endl;
            if(le[nxt]) {
                ans.pb(be[nxt]);
//                cout<<"nxt:"<<nxt<<endl;
            }
            cur = nxt;
        }
        ans.pop_back();
        reverse(all(ans));
        cout<<ans.size()<<endl;
        for(int x:ans) printf("%d ", x);
    }
    return 0;
}