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
const ll DIM = 2*10E4+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
pp A[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    forn(i,n)cin>>A[i].fi;
    forn(i,n)cin>>A[i].sc;
    vector<ll> V;
    forn(i,n){
        V.pb(A[i].sc-A[i].fi);
    }
    sort(V.begin(),V.end());
    ll res = 0;
    forn(i,n){
        ll pos = lower_bound(V.begin(),V.end(),A[i].fi-A[i].sc)-V.begin();
        if (A[i].sc-A[i].fi<A[i].fi-A[i].sc)pos--;
        res+=pos;
    }
    res/=2;
    cout<<res<<endl;
    return 0;
}
// a[i]-b[i]>b[j]-a[j]