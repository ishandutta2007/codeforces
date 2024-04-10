#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 10E4 +7;
const ll INF = 10E17;

ll n;
pp A[DIM];
map<pp,ll> M;
void add(pp x,pp y){
    ll d1 = y.sc-x.sc,d2 = y.fi-x.fi;
    pp cof = {d1,d2};
    M[cof]++;
}
ll Check(pp x,pp y){
    ll d1 = y.sc-x.sc,d2 = y.fi-x.fi;
    pp cof = {d1,d2};
    if (M.count(cof)==0)return 0;
    M[cof]--;
    if (M[cof]==0)M.erase(cof);
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    if (n%2!=0){
        cout<<"NO\n";
        return 0;
    }
    forn(i,n/2+1){
        ll x,y;
        cin>>x>>y;
        A[i] = {x,y};
        if (i!=1)
        add(A[i-1],A[i]);

    }
    A[n+1] = A[1];
    forn(i,n/2){
        ll x,y;
        if (i!=n/2){
            cin>>x>>y;
            A[i+n/2+1] = {x,y};
        }
        if (!Check(A[i+n/2+1],A[i+n/2])){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}