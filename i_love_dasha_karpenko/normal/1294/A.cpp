#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
#define x1 dsfdsfes
#define y1 sfsdfdse
#define po(x) (1ll<<x)
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 500+7;
const ll INF = 10E17;


int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(qi,t){
        ll a,b,c,n;
        cin>>a>>b>>c>>n;
        ll r = max(max(a,b),c)*3;
        ll need = r-a-b-c;
        n-=need;
        if (n%3==0 && n>=0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}