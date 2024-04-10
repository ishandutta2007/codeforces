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

ll n,a,r,m;
ll A[DIM];
ll F(ll h){
    ll took = 0;
    ll cost = 0;
    forn(i,n){
        if (A[i]>h){
            took+=A[i]-h;
        }
        else{
            if (h-A[i]>took){
                ll need = h-A[i];
                need-=took;
                cost+=took*m;
                cost+=need*a;
                took = 0;
            }
            else{
                cost+=(h-A[i])*m;
                took-=h-A[i];
            }
        }
    }

        cost+=took*r;

    return cost;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>a>>r>>m;
    m = min(m,a+r);
    forn(i,n)cin>>A[i];
    sort(A+1,A+1+n,greater<ll>());
    ll l = 0,r = 3E9;

    while(r-l>1){
        ll tl = (l*2+r)/3;
        ll tr = (r*2+l)/3;
        if (F(tl)<F(tr))r = tr-1;
        else l = tl+1;
    }

    cout<<min(F(l),F(r))<<endl;
    return 0;
}