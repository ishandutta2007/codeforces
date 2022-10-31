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
const ll DIM = 1E5+7;
const ll INF = 1e9;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll vis[DIM],m[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        forn(i,n)vis[i] = m[i] = 0;
        ll res = 0;
        forn(i,n){
            ll k;
            cin>>k;
            ll to = 0;
            forn(j,k){
                ll x;
                cin>>x;
                if (to==0 && vis[x]==0){
                    to = x;
                }
            }
            if (to!=0){
                vis[to] = 1;
                res++;
                m[i] = 1;
            }
        }
        if (res==n){
            cout<<"OPTIMAL\n";
            continue;
        }
        ll a = 0,b = 0;
        forn(i,n){
            if (m[i]==0){
                a = i;
                break;
            }
        }
        forn(i,n){
            if (vis[i]==0){
                b = i;
                break;
            }
        }
        cout<<"IMPROVE\n";
        cout<<a<<' '<<b<<endl;
    }
    return 0;
}