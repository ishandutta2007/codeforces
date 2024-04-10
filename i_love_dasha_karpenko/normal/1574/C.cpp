#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
const ll INF = 2e18;
ll A[N];
void solve(){
    int n;
    cin>>n;
    ll sum = 0;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        sum+=A[i];
    }
    sort(A+1,A+1+n);
    int m;
    cin>>m;
    for(int i = 1;i<=m;++i){
        ll x,y;
        cin>>x>>y;
        int pos = lower_bound(A+1,A+1+n,x)-A;
        ll res = INF;
        if (pos<=n){
            res = min(res,max(0ll,y-(sum-A[pos]) ) );
        }
        --pos;
        if (pos>0){
            res = min(res,max(0ll,y-(sum-A[pos]) ) + max(0ll,x-A[pos]) );
        }
        cout<<res<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}