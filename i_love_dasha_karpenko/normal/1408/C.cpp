#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
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
#define log sdfdsfdsf

const ll DIM = 2E5+7;

const ll MOD = 1e9+7;

const ll INF = 1E16+7;
const ld eps = 0.00000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
pair<ld,ll> dp[DIM],suf[DIM];
ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,l;
        cin>>n>>l;
        ll speed = 1,last = 0;
        ld ti = 0;
        dp[0] = {0,1};
        forn(i,n){
            ll x;
            cin>>x;
            A[i] = x;
            ti+=ld(x-last)/speed;
            speed++;
            last = x;
            dp[i] = {ti,speed};
        }
        speed = 1,last = l;
        ti = 0;
        suf[n+1] = {0,1};
        A[n+1] = l;
        for(ll i = n;i>=1;--i){
            ll x = A[i];

            ti+=ld(last-x)/speed;
            speed++;
            last = x;
            suf[i] = {ti,speed};
        }
        ld tl =0,tr = l;
        while(tr-tl>eps){
            ld tm = (tl+tr)/2;
            ll pos = 0;
            for(ll i = 0;i<=n;++i){
                if (dp[i].fi<=tm)pos = i;
            }
            ll pos1 = n+1;
            for(ll i = n+1;i>=1;--i){
                if (suf[i].fi<=tm)pos1 = i;
            }
            ld crd1 = A[pos]+(tm-dp[pos].fi)*dp[pos].sc;
            ld crd2 = A[pos1]-(tm-suf[pos1].fi)*suf[pos1].sc;
            if (crd1<=crd2){
                tl = tm;
            }
            else tr = tm;

        }
        cout<<fixed<<setprecision(10)<<tl<<endl;

    }
    return 0;
}