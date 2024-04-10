#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1000+7;
const ll INF = 1e19;

ll A[DIM];
set<ll> ask[DIM];
set<ll> cp[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;


    while(t--){
        memset(A,0,sizeof(A));
        ll n;
        cin>>n;
        ll cur = 0;
        forn(pos,n-1){
            ll k;
            cin>>k;
            forn(i,k){
                ll x;
                cin>>x;
                ask[pos].insert(x);
            }
        }
        vector<ll> V;
        forn(ff,n){
            forn(pos,n-1)cp[pos]  = ask[pos];
            V.clear();
            V.pb(ff);
            ll flag = 0;
            while(V.size()<n){
                forn(pos,n-1)ask[pos].erase(V.back());
                ll nx = 0;
                forn(pos,n-1){
                    if (ask[pos].size()==1)nx = pos;
                }
                if (nx==0){
                    flag = 1;
                    break;
                }
                V.pb(*ask[nx].begin());
            }

            forn(pos,n-1)ask[pos] = cp[pos];
            if (V.size()!=n){
                V.clear();
                continue;
            }
            set<ll> pd;
            forn(pos,n-1){
                ll cnt = 0;
                ll st = -1;
                ll en = -1;
                for(ll i = 0;i<n;++i){
                    if (ask[pos].count(V[i])==1){
                        ++cnt;
                        if (st==-1)st = i;
                    }
                    if (cnt==ask[pos].size()){
                        pd.insert(i);
                        en = i;
                        break;
                    }
                }
                if (en-st+1!=ask[pos].size()){
                    flag = 1;
                    break;
                }
            }
            if (pd.size()!=n-1)flag = 1;
            if (flag==0)break;
            V.clear();

        }
        for(ll to:V)cout<<to<<' ';
        cout<<endl;
        forn(i,n-1){
            ask[i].clear();
            cp[i].clear();
        }

    }
    return 0;
}