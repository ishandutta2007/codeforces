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
#define po(x) ((unsigned long long)(1)<<x)
const ll DIM = 500+7;
const ll INF = 10E17;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll res = 0;
        ll mult = 2;
        ll s1 = 0;
        ll s2 = 0;
        forn(i,n){
            if (i<n/2 || i==n)s1+=mult;
            else s2+=mult;
            mult*=2;
        }
        cout<<abs(s1-s2)<<endl;
    }
    return 0;
}