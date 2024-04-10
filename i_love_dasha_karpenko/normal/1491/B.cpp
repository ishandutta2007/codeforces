//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 100+7;
const ll INF = 1E18;
const ll MAXN = 1E6+1;
ll A[DIM];
ll solve(){
    ll n,u,v;
    cin>>n>>u>>v;
    for(ll i = 1;i<=n;++i)
        cin>>A[i];
    ll res = INF;
    for(ll i = 1;i<=n;++i){
        if (i<n && A[i]!=A[i+1])res = min(res,u);
        else res = min(res,u+v);
        if (i>1) {
            res = min(res, max(0ll, A[i] - A[i - 1] + 2) * v);
            res = min(res, max(0ll, A[i - 1] + 1 - A[i]) * v + min(u, v));

            if (A[i] < A[i - 1] - 1 || A[i] > A[i - 1] + 1)res = 0;
        }
    }
    cout<<res<<endl;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}