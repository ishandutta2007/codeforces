#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll MSZ = 2000;
const ll DIM = MSZ+7;
const ll INF = 1E18;

ll vis[DIM][DIM];
struct node{
    ll u,v,w;
};
const bool operator <(const node &a,const node &b){
    return a.w<b.w;
}

const ll ss = 2E5+7;
ll CT[ss],MI[ss],ct[DIM];
ll P[ss],cnt;
vector<ll> G[ss];
ll F(ll x){
    if (x==P[x])
        return x;
    return P[x] = F(P[x]);
}
void unite(ll a,ll b){
    a = F(a);
    b = F(b);
    if (a==b)
        return;
    --cnt;
    if (rand()%2)swap(a,b);
    P[a] = b;
    ct[b]+=ct[a];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,m;
    cin>>n>>m;
    cnt = n;
    for(ll i = 1;i<=n;++i){
        MI[i] = INF;
    }
    vector<node> E;
    for(ll i = 1;i<=n;++i){
        P[i] = i;
        ct[i] = 1;
    }
    ll total = 0;
    for(ll i = 1;i<=m;++i){
        ll u,v,w;
        cin>>u>>v>>w;
        if (n<MSZ)
            vis[u][v] = vis[v][u] = 1;
        total^=w;
        if (u>v)swap(u,v);
        G[v].push_back(u);
        E.push_back({u,v,w});
    }
    map<ll,ll> M;
    cnt = n;
    for(ll i = 1;i<=n;++i){
        for(ll to:G[i]){
            M[F(to)]--;
            if (M[F(to)]==0)
                M.erase(F(to));
        }
        for(auto to:M){
            unite(to.first,i);
        }
        M.clear();
        M[F(i)] = ct[F(i)];
        for(ll to:G[i]){
            if (M.count(F(to))==0)
                M[F(to)] = ct[F(to)];
        }
    }



    vector<node> need;

    ll flag = 0;
    if (n<MSZ) {
        for(ll i = 1;i<=n;++i)
            P[i] = i;
        cnt = n;
        for (ll i = 1; i <= n; ++i) {
            for (ll j = i + 1; j <= n; ++j) {
                if (!vis[i][j]) {
                    need.push_back({i, j, 0});
                    if (F(i) == F(j)) {
                        flag = 1;
                        total = 0;
                    }
                    unite(i, j);
                }
            }
        }
    }
    else
        flag = 1;
    sort(E.begin(),E.end());

    ll ans = INF;
    if (flag){
        ll res = 0;
        for(auto to:E){
            if (F(to.v)!=F(to.u)){
                unite(to.u,to.v);
                res+=to.w;
            }
        }
        cout<<res<<endl;
        return 0;
    }
    for(node cur:need) {
        cnt = n;
        for(ll i = 1;i<=n;++i)
            P[i] = i;
        for(node to:need){
            if (to.v==cur.v && to.u==cur.u)
                continue;
            unite(to.u,to.v);
        }
        node edg = cur;
        edg.w = total;
        ll res = 0;
        for (node to:E) {
            if (to.w >= edg.w) {
                if (F(edg.v) != F(edg.u)) {
                    res += edg.w;
                    unite(edg.v, edg.u);
                }
            }
            if (F(to.v) != F(to.u)) {
                res += to.w;
                unite(to.v, to.u);
            }
        }
        if (F(edg.v) != F(edg.u)){
            res += edg.w;
            unite(edg.v, edg.u);
        }

        ans = min(ans, res);

    }
    cout<<ans<<endl;
    return 0;
}