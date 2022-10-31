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
const ll DIM = 3*10E4+7;
const ll INF = 10E17;


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(qe,t){
        ll n,g,b;
        cin>>n>>g>>b;
        ll bsum = n/2+n%2;
        if (g>b){
            cout<<n<<endl;
        }
        else{
            ll sum = (b+g);
            ll cnt = bsum/g;
            if (bsum%g==0)cnt--;
            ll res = cnt*sum+bsum-cnt*g;
            ll sum2 = cnt*b;
            if (sum2+cnt*g+bsum-cnt*g<n)res+=n-(sum2+cnt*g+bsum-cnt*g);
            cout<<res<<endl;

        }
    }
    return 0;
}