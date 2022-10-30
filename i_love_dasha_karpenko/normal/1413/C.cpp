#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
#define sc second
#define pb push_back
#define fi first
const ll DIM = 1E5+7;
ll A[7],B[DIM],cur[DIM];
typedef pair<ll,ll> pp;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll strs = 6;
    for(ll i = 1;i<=strs;++i)cin>>A[i];
    sort(A+1,A+1+strs);
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i)cin>>B[i];
    sort(B+1,B+1+n);
    vector<pp> difs;
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=strs;++j){
            difs.pb({B[i]-A[j],i});
        }
    }
    sort(difs.begin(),difs.end(),greater<pp>());
    ll ptr = 1;
    ll sum = B[n]-B[1];
    for(ll i = 1;i<=n;++i)cur[i] = 1;
    ll res = 1E18;
    set<pp> S;
    for(ll i = 1;i<=n;++i){
        S.insert({B[i]-A[1],i});
    }
    for(pp to:difs){
        res = min(res,S.rbegin()->first-S.begin()->first);
        S.erase({B[to.sc]-A[cur[to.sc]],to.sc});
        if (to.fi==B[to.sc]-A[cur[to.sc]+1])
        cur[to.sc]++;
        S.insert({B[to.sc]-A[cur[to.sc]],to.sc});
    }
    res = min(res,S.rbegin()->first-S.begin()->first);
    cout<<res<<endl;
    return 0;

}