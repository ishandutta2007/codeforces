#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 507;
const ll INF = 10000000007;
const ll MOD = ll(1000000007) ;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 Artem
#define y1 Pidor
const ll LOG = 9;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> my_super_set;

ll t;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    forn(query,t){
        ll a,b; cin>>a>>b;
        if (a>b)swap(a,b);
        ll g= __gcd(a,b);
        if (g==1){
            cout<<"Finite\n";
        }
        else cout<<"Infinite\n";
    }
    return 0;
}