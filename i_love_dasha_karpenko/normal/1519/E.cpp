//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 4E5+7;
typedef pair<ll,ll> pp;
pair<pp,pp> A[DIM];
#define fi first
#define sc second
pp F(ll x1,ll x2,ll y1,ll y2){
    pp k = {y1*x2,x1*y2};
    ll g = __gcd(k.fi,k.sc);
    k.fi/=g;
    k.sc/=g;
    return k;
}
vector<pair<ll,ll> > G[DIM];
set<ll> E[DIM];
ll vis[DIM];
void dfs(ll v){
    vis[v] = 1;
    for(auto [to,el]:G[v]){
        if (vis[to]==1)
            continue;
        if (vis[to]==0)
            dfs(to);
        
        if (E[to].size()%2!=0){
            E[to].erase(el);
        }
        else{
            E[v].erase(el);
        }
    }
    vis[v] = 2;
}
void solve(){
    ll n;
    cin>>n;
    set<pair<ll,ll> > S;
    for(ll i = 1;i<=n;++i){
        ll x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        pp k1 = F(x1+x2,x2,y1,y2);
        pp k2 = F(x1,x2,y1+y2,y2);
        S.insert(k1);
        S.insert(k2);
        A[i] = {k1,k2};
    }
    map<pp,ll> M;
    ll ptr = 0;
    for(pp to:S){
        M[to] = ++ptr;
    }
    for(ll i = 1;i<=n;++i){
        ll a = M[A[i].fi];
        ll b = M[A[i].sc];
        G[a].push_back({b,i});
        G[b].push_back({a,i});
        E[a].insert(i);
        E[b].insert(i);
    }
    for(ll i = 1;i<=ptr;++i){
        if (vis[i])
            continue;
        dfs(i);
    }
    vector<pair<ll,ll> > ans;
    for(ll i = 1;i<=ptr;++i){
        ll last = -1;
        for(ll to:E[i]){
            if (last==-1)
                last = to;
            else{
                ans.push_back({to,last});
                last = -1;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto to:ans)
        cout<<to.first<<' '<<to.second<<endl;

}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    t = 1;
    while(t--)
        solve();
    return 0;
}