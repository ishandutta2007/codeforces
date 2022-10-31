#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 2E5+7;
ll w[DIM];
vector<ll> G[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll res = 0;
        map<ll,ll> M;
        for(ll i = 1;i<=n;++i){
            cin>>w[i];
            res+=w[i];
        }
        for(ll i = 1;i<n;++i){
            ll u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        priority_queue<ll> Q;
        for(ll i = 1;i<=n;++i){
            for(ll j = 1;j<G[i].size();++j)Q.push(w[i]);
        }
        for(ll i = 1;i<n;++i){
            cout<<res<<' ';
            if (i+1!=n){
                res+=Q.top();
                Q.pop();
            }
        }

        cout<<endl;
        for(ll i = 1;i<=n;++i)G[i].clear();
    }

    return 0;
}