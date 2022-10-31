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
const ll DIM = 1E6+14;
const ll INF = 1E19;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,s;
    cin>>n>>s;
    ll avg = s/n;
    if (avg==1){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";

    forn(i,n-1){
        cout<<avg<<' ';
    }
    cout<<s-avg*(n-1)<<endl;
    cout<<s-1<<endl;
    return 0;
}