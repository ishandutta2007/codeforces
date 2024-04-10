#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 20;
const ll masksz = (1ll<<19);
ll dp[masksz+7][DIM];
ll G[DIM][DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=m;++i){
        ll u,v;
        cin>>u>>v;
        G[u][v] = G[v][u] = 1;//

    }
    ll sz = (1<<n);
    ll res = 0;
    for(ll mask = 1;mask<sz;++mask){
        ll frs = 0;
        for(ll last = 1;last<=n;++last){
            if (!(mask&(1<<(last-1))))continue;
            if (frs==0)frs = last;
            ll submask = mask^(1<<(last-1));
            if (submask==0){
                dp[mask][last] = 1;
                continue;
            }
            if (frs==last)continue;
            for(ll prev = 1;prev<=n;++prev){
                if (prev==last)continue;
                if (!(submask&(1<<(prev-1))))continue;
                if (G[last][prev]==0)continue;
                dp[mask][last]+=dp[submask][prev];
            }
            if (G[frs][last] && __builtin_popcount(mask)>2)res+=dp[mask][last];
        }
    }

    cout<<res/2<<endl;
    return 0;
}