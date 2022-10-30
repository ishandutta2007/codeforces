#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 5E5+7;
const ll INF = 1E18;
ll vis[DIM],A[DIM],el[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    for(ll i = 1;i<=n;++i)cin>>A[i];
    for(ll i = 1;i<=k;++i){
        ll x;
        cin>>x;
        vis[x] = 1;
    }
    vector<pair<ll,ll> > V;// ddd
    ll st = -1;
    for(ll i = 1;i<=n;++i){
        if (vis[i]==0 && st==-1){
            st = i;
        }
        if (vis[i]==1 && st!=-1){
            V.push_back({st,i-1});
            st = -1;
        }
        if (vis[i]==1 && vis[i-1]==1 && A[i]<=A[i-1]){
            cout<<-1<<endl;
            return 0;
        }
    }
    if (st!=-1)V.push_back({st,n});
    A[0] = -INF;
    A[n+1] = INF;
    ll res = 0;
    for(auto to:V){
        if (A[to.second+1]-A[to.first-1]<to.second-to.first+2){
            cout<<-1<<endl;
            return 0;
        }
        ll ptr = 0;
        el[0] = -INF;
        for(ll i = to.first;i<=to.second;++i){
            if (A[i]-A[to.first-1]<i-to.first+1 || A[to.second+1]-A[i]<to.second+1-i)continue;
            if (el[ptr]<=A[i]-i){
                ++ptr;
                el[ptr] = A[i]-i;
                continue;
            }
            ll pos = upper_bound(el,el+ptr,A[i]-i)-el;
            if (pos>ptr){
                ++ptr;
                el[pos] = A[i]-i;
            }
            else{
                el[pos] = min(el[pos],A[i]-i);
            }
        }
        res+=(to.second-to.first+1)-ptr;
    }
    cout<<res<<endl;
    return 0;

}