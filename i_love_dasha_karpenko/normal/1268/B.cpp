#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 300000+7;
const ll INF = 10E17;

ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll b = 0,w = 0;
    forn(i,n){
        ll x; cin>>x;
        ll cnt1 = x/2+x%2;
        ll cnt2 = x/2;
        if (i%2==1){
            b+=cnt1;
            w+=cnt2;
        }
        else{
            w+=cnt1;
            b+=cnt2;
        }
    }
    cout<<min(b,w)<<endl;
    return 0;
}
// 9 7+2