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
//#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E4+7;
const ll INF = 1E16;

vector<ll> V[DIM];
ll ask(ll l,ll r){
    cout<<"? "<<r-l+1<<' ';
    for(ll i = l;i<=r;++i)cout<<i<<' ';
    cout<<endl;
    ll ret;
    cin>>ret;
    return ret;
}
ll ans[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        forn(i,k){
            ll c;
            cin>>c;
            V[i].resize(c);
            for(ll j = 0;j<c;++j){
                cin>>V[i][j];
            }
        }
        ll mx = ask(1,n);
        ll l = 1,r = n;
        while(l!=r){
            ll tm = (l+r)/2;
            if (ask(l,tm)==mx)r = tm;
            else l = tm+1;
        }
        forn(i,k){
            ll flag = 0;
            for(ll to:V[i]){
                if (to==l){
                    flag = 1;
                    break;
                }
            }
            if (flag){
                set<ll> S;
                forn(u,n)S.insert(u);
                for(ll to:V[i])S.erase(to);
                cout<<"? "<<S.size()<<' ';
                for(ll to:S)cout<<to<<' ';
                cout<<endl;
                ll ret;
                cin>>ret;
                ans[i] = ret;
            }
            else{
                ans[i] = mx;
            }
            V[i].clear();
        }
        cout<<"! ";
        forn(i,k)cout<<ans[i]<<' ';
        cout<<endl;
        string ssss;
        cin>>ssss;

    }
    return 0;
}