#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E5+14;
const ll INF = 1E19;

ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        forn(i,n)cin>>A[i];
        sort(A+1,A+1+n);
        ll res = 1;
        forn(i,n){
            if (i>=A[i])res = i+1;
        }
        cout<<res<<endl;
    }
    return 0;
}