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

const ll DIM = 2E5  +7;

const ll MOD = 1e9+7;

const ll INF = 1E18+70;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
ll pref[DIM][3],suf[DIM][3],A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n){
        cin>>A[i];
    }
    if (1==n){
        cout<<A[1]<<endl;
        return 0;
    }
    pref[0][1] = pref[0][2] = -INF;
    forn(i,n){
        for(ll j = 0;j<3;++j){
            pref[i][j] = max(pref[i-1][j]+A[i],pref[i-1][(j-1+3)%3]-A[i]);
        }
    }
    suf[n+1][1] = suf[n+1][2] = -INF;
    for(ll i = n;i>=1;--i){
        for(ll j = 0;j<3;++j){
            suf[i][j] = max(suf[i+1][j]+A[i],suf[i+1][(j-1+3)%3]-A[i]);
        }
    }
    ll res = -INF;
    for(ll i = 1;i<=n-1;++i){
        ll ct = 2;
        ll sum = -A[i]-A[i+1];

        for(ll j = 0;j<3;++j){
            res= max(res,pref[i-1][j]+sum+suf[i+2][((1-n-ct-j)%3+3)%3]);
        }
        ct = 0;
        sum = A[i]+A[i+1];
        for(ll j = 0;j<3;++j){
            res= max(res,pref[i-1][j]+sum+suf[i+2][((1-n-ct-j)%3+3)%3]);
        }

    }
    cout<<res<<endl;
    return 0;
}