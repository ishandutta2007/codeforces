#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N,M;
ll kek[100010];
bool vis[100010];
ll sx,sy,ex,ey,x,y;
vector<pll> adj[100010];
int main(){
    cin >> N >> M;
    for(int i = 0; i < 100010; i++)kek[i]=100000000000000;
    vector<pll> kwk;
    cin >> sx >> sy >> ex >> ey;
    kwk.pb({sx,sy});
    while(M--){
        cin >> x >> y;
        kwk.pb({x,y});
    }
    M = kwk.size();
    int start;
    sort(kwk.begin(),kwk.end());
    vector<pll> kok;

    for(int i = 0; i < M; i++){
        if(i){
            adj[i].pb({i-1,kwk[i].fi-kwk[i-1].fi});
            adj[i-1].pb({i,kwk[i].fi-kwk[i-1].fi});
        }
        if(i<M-1){
            adj[i].pb({i+1,kwk[i+1].fi-kwk[i].fi});
            adj[i+1].pb({i,kwk[i+1].fi-kwk[i].fi});
        }
        if(kwk[i].fi == sx && kwk[i].se == sy)start = i;
        kok.pb({kwk[i].se,i});
    }
    sort(kok.begin(),kok.end());
    for(int i = 0; i < M; i++){
        if(i){
            adj[kok[i].se].pb({kok[i-1].se,kok[i].fi-kok[i-1].fi});
            adj[kok[i-1].se].pb({kok[i].se,kok[i].fi-kok[i-1].fi});
        }
        if(i<M-1){
            adj[kok[i].se].pb({kok[i+1].se,kok[i+1].fi-kok[i].fi});
            adj[kok[i+1].se].pb({kok[i].se,kok[i+1].fi-kok[i].fi});
        }
        if(kwk[i].fi == sx && kwk[i].se == sy)start = i;
    }
    kek[start]=0; ll d,node;
    priority_queue<pll> pq;
    pq.push({0,start});
    while(!pq.empty()){
        d = -pq.top().fi;
        node = pq.top().se;
        pq.pop();
        if(vis[node])continue;
        vis[node] = 1;
        for(auto x: adj[node]){
            if(d+x.se<kek[x.fi]){
                kek[x.fi] = d+x.se;
                pq.push({-d-x.se,x.fi});
            }
        }
    }
    ll ans = 1000000000000;
    for(int i = 0; i < M; i++){
        ans = min(ans,kek[i]+abs(ex-kwk[i].fi)+abs(ey-kwk[i].se));
    }
    cout << ans <<"\n";
    return 0;
}