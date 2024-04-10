#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long ll;

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
#define log sdfdsfdsf

const ll DIM = 2000+7;
const ll DIM2 = 1E6+7;
const ll MOD = 1e9+7;

const ll INF = 1E16+7;
const ld eps = 0.00000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
const ll MAXN = 1E6;
vector<pp> ans;
void solve(ll l,ll r){
    if (l==r)return;
    ll tm = (l+r)/2;
    solve(l,tm);
    solve(tm+1,r);
    ll dif = tm+1-l;
    for(ll i = l;i<=tm;++i){
        ans.pb({i,i+dif});
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll power = 0,val = 1;
    while(val*2<=n){
        val*=2;
        ++power;
    }
    solve(1,val);
    if (val!=n)
    solve(n-val+1,n);

    cout<<ans.size()<<endl;
    for(pp to:ans)cout<<to.fi<<' '<<to.sc<<endl;

    return 0;
}