#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll MOD = 998244353 ;
const ll DIM = 2E5+7;
const ll LOG = 30;
const ll INF = 1E17;
vector<pair<ll,ll> > G[DIM];
pair<ll,ll> dist[2][LOG+1][DIM];
ll vis[2][LOG+1][DIM];
struct node{
    pair<ll,ll> val;
    ll ind,lg,v;
};
ll binpow(ll x,ll power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)x = (x*mult)%MOD;
        mult = (mult*mult)%MOD;
        power/=2;
    }
    return x;
}
bool mc(pair<ll,ll> a,pair<ll,ll> b){
    if (a.first==b.first)return a.second<b.second;
    //if (a.second==b.second)return a.first<b.first;
    if (a.first<=LOG && b.first<=LOG){
        ll v1 = (1ll<<a.first)+a.second;

        ll v2 = (1ll<<b.first)+b.second;

        return v1<v2;
    }
    else {
        if (a.first==b.first)a.second<b.second;
        return a.first<b.first;
    }
}
const bool operator>(const node &a,const node &b){
    return mc(b.val,a.val);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=m;++i){
        ll u,v;
        cin>>u>>v;
        G[u].push_back({v,0});
        G[v].push_back({u,1});
    }
    priority_queue<node,vector<node>,greater<node> > Q;
    for(ll i = 1;i<=n;++i){
        for(ll j = 0;j<=LOG;++j)
        dist[0][j][i] = dist[1][j][i] = {INF,INF};
    }
    dist[0][0][1] = {0,0};
    Q.push({{0,0},0,0,1});
    while(!Q.empty()){
        ll ind = Q.top().ind;
        ll v = Q.top().v;
        ll lg = Q.top().lg;
        Q.pop();
        if (vis[ind][lg][v]==1)continue;
        vis[ind][lg][v] = 1;
        pair<ll,ll> vv = dist[ind][lg][v];
        vv.first++;
        ll lg1 = min(lg+1,LOG);
        if ( mc(vv,dist[ind^1][lg1][v])){
            dist[ind^1][lg1][v] = vv;
            Q.push({vv,ind^1,lg1,v});
        }
        for(auto to:G[v]){
            if (to.second!=ind)continue;
            pair<ll,ll> sum = dist[ind][lg][v];
            ll ni = to.second;

            sum.second++;
            if (mc(sum,dist[ni][lg][to.first])){
                dist[ni][lg][to.first] = sum;
                Q.push({sum,ni,lg,to.first});
            }
        }
    }
    pair<ll,ll> ans = {INF,INF};
    for(ll j = 0;j<=LOG;++j){
        if (mc(dist[0][j][n],ans))ans = dist[0][j][n];


        if (mc(dist[1][j][n],ans))ans = dist[1][j][n];

    }
    cout<<(binpow(2,ans.first)-1+ans.second+MOD)%MOD<<endl;



    return 0;

}