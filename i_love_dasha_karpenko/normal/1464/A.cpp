#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
pair<ll,ll> A[DIM];
vector<ll> G[DIM];
ll vis[DIM],flag = 0;
void dfs(ll v){
    vis[v] = 1;
    for(ll i = 0;i<G[v].size();++i){
        ll to = G[v][i];
        if (vis[to]==0)dfs(to);
        //dfs(to);
    }
    if (G[v].size()<=1)flag = 1;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;

        map<ll,ll > V1,V2;
        for(ll i = 1;i<=m;++i){
            cin>>A[i].first>>A[i].second;
            if (V1.count(A[i].second)==0)V2[A[i].second] = i;
            else{
                G[i].push_back(V1[A[i].second]);
                G[V1[A[i].second]].push_back(i);
            }
            if (V2.count(A[i].first)==0 || V2[A[i].first]==i)V1[A[i].first] = i;
            else{
                G[i].push_back(V2[A[i].first]);
                G[V2[A[i].first]].push_back(i);
            }
        }
        ll res = 0;
        for(ll i = 1;i<=m;++i){
            if (A[i].first==A[i].second){
                res--;
                continue;
            }
            if (vis[i]==0){
                flag = 0;
                dfs(i);
                res+=(flag^1);
            }
        }
        res+=m;
        cout<<res<<endl;
        for(ll i = 1;i<=m;++i){
            G[i].clear();
            vis[i] = 0;
        }
    }
    return 0;
}