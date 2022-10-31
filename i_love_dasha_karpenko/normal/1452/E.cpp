#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 2007;
pair<ll,ll> A[DIM];
ll dp[DIM],add[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    for(ll i = 1;i<=m;++i){
        cin>>A[i].first>>A[i].second;
    }
    ll res = 0;
    for(ll i = k;i<=n;++i){
        ll l = i-k+1;
        ll r = i;
        ll sum = 0;

        for(ll j = 1;j<=m;++j){
             ll l1 = max(l,A[j].first),r1 = min(A[j].second,r);
            sum+=max(0ll,r1-l1+1);
            if (r1-l1+1!=min(A[j].second-A[j].first+1,k) && A[j].first<l && l-1<=A[j].second){
                ll R = min(A[j].second,r);
                ll pos = R-l+A[j].first+1;
                if (pos>0 && pos<=i){
                    add[pos]++;

                    add[i]--;
                }
            }

        }
        add[0] = 0;
        for(ll j = 1;j<=n;++j){
            add[j]+=add[j-1];
            dp[j] += add[j];
            if (j<=i)
            res = max(res,sum+dp[j]);
        }
        for(ll j= 1;j<=n;++j)add[j] = 0;
    }
    cout<<res<<endl;

    return 0;
}