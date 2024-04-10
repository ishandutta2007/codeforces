#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 5E5+7;
const ll INF = 1E18;
struct node{
    ll u,v,t;
};
node edges[DIM];
pair<ll,ll> Q[DIM];
pair<ll,ll> upd[DIM];
ll P[DIM],sz[DIM],A[DIM];
set<pair<ll,ll> > S[DIM];
vector<ll> V[DIM];
ll F(ll x){
    if (x==P[x])return x;
    return F(P[x]);
}
void unite(ll a,ll b,ll time){
    a = F(a);
    b = F(b);
    if (a==b)return;
    if (sz[a]<sz[b])swap(a,b);
    P[b] = a;
    sz[a]+=sz[b];
    for(auto to:S[b])S[a].insert(to);
    if (time!=INF){
        upd[time] = {a,b};
    }
}
bool mc(node &a,node &b){
    return a.t<b.t;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,q;
    cin>>n>>m>>q;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        P[i] = i;
        sz[i] = 1;
        S[i].insert({A[i],i});
    }
    for(ll i = 1;i<=m;++i){
        cin>>edges[i].u>>edges[i].v;
        edges[i].t = INF;
    }
    for(ll i = 1;i<=q;++i){
        cin>>Q[i].first>>Q[i].second;
        if (Q[i].first==2){
            edges[Q[i].second].t = i;
        }
    }
    sort(edges+1,edges+1+m,mc);
    for(ll i = m;i>=1;--i){
        unite(edges[i].u,edges[i].v,edges[i].t);
    }
    for(ll i = 1;i<=q;++i){
        if (Q[i].first==1){
            ll par = F(Q[i].second);
            while(!S[par].empty() && A[S[par].rbegin()->second]==0)
                S[par].erase(*S[par].rbegin());
            if (S[par].empty())cout<<0<<endl;
            else {
                cout<<S[par].rbegin()->first<<endl;
                A[S[par].rbegin()->second] = 0;
            }
        }
        else{
            ll a = upd[i].first,b = upd[i].second;
            for(auto to:S[b])S[a].erase(to);
            P[b] = b;
        }
    }
    return 0;
}