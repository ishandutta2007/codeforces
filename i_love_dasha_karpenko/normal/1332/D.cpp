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
const ll DIM = 2E5+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
//

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll k;
    cin>>k;
    ll num = 1;
    while(num<=k)num*=2;
    ll a = k|num;
    cout<<3<<' '<<3<<endl;
    forn(i,3){
        forn(j,3){
            if ((i==1 && j==1) || (i==3 && j==2)){
                cout<<a<<' ';
                continue;
            }
            if (j==1 || (j==3 && i==3)){
                cout<<k<<' ';
                continue;
            }
            cout<<num<<' ';
        }
        cout<<endl;
    }
    return 0;
}