#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int N = 5007;
const ll MOD = 1e9+7;
vector<int> G[N],C[N];
int L[N],R[N],state[N];
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        int col; cin>>col; G[col].push_back(i);
    }
    for(int i = 1;i<=m;++i){
        int f,h; cin>>f>>h;
        if (G[f].size()<h)
            continue;
        L[i] = G[f][h-1],R[i] = G[f][int(G[f].size())-h];
        C[f].push_back(i);
    }
    pair<ll,ll> res = {0,1};
    //memset(state,-1,sizeof(state));
    for(int mid = 0;mid<=n;++mid){
        pair<ll,ll> cur = {0,1};
        ll wb = 1;
        for(int col = 1;col<=n;++col){
            if (C[col].empty())
                continue;
            ll dp[3] = {0,0,0},smu[3] = {0,0,0};
            bool can[3] = {0,0,0};
            for(int i:C[col]){
                int st = int(L[i]<=mid) + int(R[i]>mid)*2;
                int ol = state[i];
                state[i] = st;
                if (st&1)
                    dp[2] = (dp[2]+dp[1])%MOD,can[2] = max(can[2],can[1]);
                if (st&2)
                    dp[2] = (dp[2]+dp[0])%MOD,can[2] = max(can[2],can[0]);
                if (st&1)
                    dp[0]++,can[0] = 1;
                if (st&2)
                    dp[1]++,can[1] = 1;
                st&=ol;
                if (st&1)
                    smu[2] = (smu[2]+smu[1])%MOD;
                if (st&2)
                    smu[2] = (smu[2]+smu[0])%MOD;
                if (st&1)
                    smu[0]++;
                if (st&2)
                    smu[1]++;
            }

            if (can[2])
                cur.first+=2,cur.second = cur.second*dp[2]%MOD,wb = wb*smu[2]%MOD;
            else if (can[0] || can[1])
                cur.first++,cur.second = cur.second*(dp[0]+dp[1])%MOD,wb = wb*(smu[0]+smu[1])%MOD;

        }
        cur.second = (cur.second+MOD-wb)%MOD;
        if (res.first<cur.first)
            res = {cur.first,0};
        if (cur.first==res.first)
            res.second+=cur.second;
    }
    cout<<res.first<<' '<<res.second%MOD<<endl;
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
   // cin>>t;
    while(t--)
        solve();
}