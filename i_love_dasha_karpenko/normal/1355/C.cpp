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
const ll DIM = 2E5+14;
const ll INF = 1E19;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll res = 0;
    for(ll x = a;x<=b;++x){
        ll dif = d-x+1;
        dif = max(dif,b);
        if (dif<=c){
            res+=(d-c+1)*(c-dif+1);
            dif--;
        }

        dif = min(dif,c);
        ll base = dif+x-c;
        ll len = min(dif-b+1,base);
        base-=len;
        res+=len*(len+1)/2+base*len;
    }
    cout<<res<<endl;
    return 0;
}