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
const ll INF = 1e9;

pp to[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    forn(i,k){
        ll x,y;
        cin>>x>>y;

    }
    forn(i,k){
        ll x,y;
        cin>>x>>y;
        to[i] = {x,y};
    }
    cout<<n-1+m-1+n*m-1<<endl;
    forn(i,n-1){
        cout<<'U';
    }
    forn(i,m-1){
        cout<<'L';
    }
    ll flag = 0;
    forn(i,n){
        forn(j,m-1){
            if (flag==0)cout<<'R';
            else cout<<'L';
        }
        flag^=1;
        if (i!=n)
        cout<<'D';
    }
    return 0;
}