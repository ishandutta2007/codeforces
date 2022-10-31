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
#define po(x) (1ll<<x)
const ll DIM = 100+14;
const ld INF = 1E10;
const ld PI =  3.14159265358979323846;
ll gi(char ch){
    return ch-'1';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ld n;
        cin>>n;
        n*=2;
        ld angle = 360.0/n;
        ld con = (180.0-angle)/2.0;
        ld res = 1/cos(con*PI/180.0);
        ld ans = INF;
        ld con1 = (180.0-angle/2.0)/2;
        res *=sin(con1*PI/180.0);
        cout<<fixed<<setprecision(10)<<res<<endl;

    }
    return 0;
}