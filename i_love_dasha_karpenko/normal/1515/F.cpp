//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 3E5+7;
ll A[DIM],P[DIM];
vector<pair<ll,ll> > G[DIM];
set<pair<ll,pair<ll,ll> > > S[DIM];
ll F(ll x){
    if (x==P[x])
        return x;
    return P[x] = F(P[x]);
}
ll unite(ll x,ll y){
    x = F(x);
    y = F(y);
    if (x==y)
        return 0;
    P[x] = y;
    return 1;
}
vector<ll> ans;
ll n,m,x;
void merge(ll a,ll b){
    if (S[a].size()<S[b].size())
        swap(S[a],S[b]);
    for(auto to:S[b])
        S[a].insert(to);
    A[a]+=A[b]-x;
}
void solve(ll v,ll par){
    for(auto [to,ind]:G[v]){
        if (to==par)
            continue;
        solve(to,v);
        S[v].insert({x-A[to],{to,ind} });
    }
    while(!S[v].empty() && S[v].begin()->first<=A[v]){
        auto t = *S[v].begin();
        S[v].erase(S[v].begin());
        ans.push_back(t.second.second);
        merge(v,t.second.first);
    }
}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>x;
    ll sum = 0;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        sum+=A[i];
        P[i] = i;
    }
    if ((n-1)*x>sum){
        cout<<"NO\n";
        return 0;
    }

    for(ll i = 1;i<=m;++i){
        ll x,y;
        cin>>x>>y;
        if (unite(x,y)){
            G[x].push_back({y,i});
            G[y].push_back({x,i});
        }
    }
    solve(1,1);
    cout<<"YES\n";
    if (ans.size()!=n-1)
        n/=0;
    for(ll to:ans)
        cout<<to<<endl;

    return 0;
}