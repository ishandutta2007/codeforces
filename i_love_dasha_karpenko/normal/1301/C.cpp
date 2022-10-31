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
const ll DIM = 2000+7;
const ll INF = 10E17;


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll te;
    cin>>te;
    while(te--){
        ll n,m;
        cin>>n>>m;
        if (m==0){
            cout<<0<<endl;
            continue;
        }
        ll sum = n*(n+1)/2;
        ll shift = (n-m)/(m+1);

        ll c = n-(shift+1)*m;
        sum-=(m+1)*shift*(shift+1)/2+(shift+1)*((n-m)%(m+1));
        cout<<sum<<endl;
    }

    return 0;
}