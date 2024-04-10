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
const ll DIM = 1E4+7;
const ll INF = 1E16;

vector<ll> G[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        forn(i,n-1){
            ll a,b;
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        if (G[x].size()<=1){
            cout<<"Ayush\n";
        }
        else{

            ll sz = n-3;
            if (sz%2==0)cout<<"Ashish\n";
            else{
                cout<<"Ayush\n";
            }
        }
        forn(i,n)G[i].clear();
    }
    return 0;
}