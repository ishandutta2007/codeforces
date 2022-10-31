#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1000+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
//
ll F(ll x){
    for(ll i = 2;i<=sqrt(x);++i){
        if (x%i==0)return 0;
    }
    return 1;
}
vector<ll> simp;
ll col[30],A[DIM];
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(ll i = 2;i<=sqrt(1000);++i){
        if (F(i))simp.pb(i);
    }
    //cout<<simp.size()<<endl;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
       // cout<<11<<endl;
       memset(col,0,sizeof(col));
        forn(j,n){
            ll x;
            cin>>x;
            A[j] = x;
            for(ll i = 0;i<simp.size();++i){
                if (x%simp[i]==0){
                    col[i+1] = 1;
                    break;
                }
            }
        }
        ll ptr = 0;
        for(ll i = 1;i<=11;i++){
            if (col[i]==0)continue;
            col[i] = ++ptr;
        }
        cout<<ptr<<endl;
        forn(j,n){
            ll x;

            x= A[j];
            for(ll i = 0;i<simp.size();++i){
                if (x%simp[i]==0){
                    cout<<col[i+1]<<' ';
                    break;
                }
            }
        }
        cout<<endl;

    }
    return 0;
}