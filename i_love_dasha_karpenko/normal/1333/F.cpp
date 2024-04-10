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
const ll DIM = 5E5+7;
const ll INF = 1e18;
ll vis[DIM],R[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll cnt = 0;
    for(ll i = 2;i<=n;++i){
        if (vis[i]!=0)continue;
        cnt++;
        for(ll j = i*i;j<=n;j+=i)if (vis[j]==0)vis[j] = i;
    }
    ll ptr = 1;
    forn(i,n){
        if (vis[i]!=0)
        R[i] = i/vis[i];
        else R[i] = 1;
    }
    sort(R+1,R+1+n);
    for(ll i = 2;i<=n;++i){
        cout<<R[i]<<' ';
    }
    cout<<endl;
    return 0;
}