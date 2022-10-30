#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E6+7;
const ll INF = 1E18+7;
ll A[4][DIM],dp[4][DIM];
set<ll> G[4][DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n[4];
    cin>>n[0]>>n[1]>>n[2]>>n[3];
    for(ll type = 0;type<4;++type){
        for(ll i = 1;i<=n[type];++i){
            cin>>A[type][i];
        }
    }
    for(ll type = 0;type<3;++type){
        ll m;
        cin>>m;
        while(m--){
            ll x,y;
            cin>>x>>y;
            G[type][x].insert(y);
        }
    }
    for(ll i = 1;i<=n[3];++i){
        dp[3][i] = A[3][i];
    }
    for(ll type = 2;type>=0;--type){
        priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > Q;
        for(ll i = 1;i<=n[type+1];++i)
            Q.push({dp[type+1][i],i});
        for(ll i = 1;i<=n[type];++i){

            dp[type][i] = INF;
            queue<pair<ll,ll> > qq;
            while(!Q.empty()){
                if (G[type][i].count(Q.top().second)){
                    qq.push(Q.top());
                    Q.pop();
                    continue;
                }
                dp[type][i] = Q.top().first+A[type][i];
                break;
            }
            while(!qq.empty()){
                Q.push(qq.front());
                qq.pop();
            }
        }
    }
    ll res = INF;
    for(ll i = 1;i<=n[0];++i){
        res = min(res,dp[0][i]);
    }
    if (res>=INF)cout<<"-1\n";
    else
    cout<<res<<endl;
    return 0;
}