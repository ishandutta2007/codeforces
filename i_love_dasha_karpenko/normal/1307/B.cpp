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
const ll DIM = 10E4+7;
const ll INF = 10E17;


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll mx = 0,flag = 0;
        forn(i,n){
            ll a;
            cin>>a;
            mx = max(mx,a);
            if (a==x)flag = 1;
        }

        ll res = max(1ll,x/mx);
        if (x%mx!=0)res++;
        if (flag==1)res = 1;
        cout<<res<<endl;
    }
    return 0;
}