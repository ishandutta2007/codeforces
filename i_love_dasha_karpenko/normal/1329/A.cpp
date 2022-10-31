#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E5+7;
const ll INF = 1e8;

ll n,m;
ll A[DIM];
ll lim[DIM],ans[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    ll sum = 0;
    forn(i,m){
        cin>>A[i];
        sum+=A[i];
    }
    ll pos = 1;
    lim[m+1] = n+1;
    for(ll i = m;i>=1;--i){
        lim[i] = min(lim[i+1]-1,n-A[i]+1);
    }
    if (lim[1]<1){
        cout<<"-1\n";
        return 0;
    }
    forn(i,m){
        ans[i] = pos;
        pos = min(pos+A[i],lim[i+1]);
    }
    ll flag = 0;
    forn(i,m-1){

        if (ans[i]==ans[i+1]){
            cout<<"-1\n";
            return 0;
        }
    }
    forn(i,m){
        if (ans[i]+A[i]-1==n)flag = 1;
    }
    if (flag==0){
        cout<<"-1\n";
            return 0;
    }
    forn(i,m)cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}