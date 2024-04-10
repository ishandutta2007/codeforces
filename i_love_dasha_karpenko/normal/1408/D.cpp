#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long ll;

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

const ll DIM = 2000+7;
const ll DIM2 = 1E6+7;
const ll MOD = 1e9+7;

const ll INF = 1E16+7;
const ld eps = 0.00000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
const ll MAXN = 1E6;
pp A[DIM],B[DIM];
vector<pp> V[DIM2];
ll mx[DIM];
ll suf[DIM],n,m;
bool mc(pp a,pp b){
    return a.sc>b.sc;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin>>n>>m;
    forn(i,n){
        cin>>A[i].fi>>A[i].sc;
    }
    forn(i,m)cin>>B[i].fi>>B[i].sc;
    sort(B+1,B+1+m);
    B[m+1] = {INF,INF};
    ll ans = 0;
    forn(i,n){
        suf[m+1] = 0;
        for(ll j = m;j>=1;--j){
            suf[j] = max(suf[j+1],B[j].sc-A[i].sc+1);
        }
        ll nx = max(long(0),B[1].fi-A[i].fi);
        V[nx].pb({suf[1],i});
        ll an = suf[1];
        forn(j,m){
            if (B[j].fi<A[i].fi)an = min(an,suf[j+1]);
            ll r = 0;
            ll mup = 0;

            r = suf[j+1];
            mup = max(mup,B[j+1].fi-A[i].fi);
            mup = min(mup,DIM2-1);
            V[mup].pb({r,i});

        }
        ans = max(an,ans);
    }


    ll res = INF;
    forn(i,n)mx[i] = INF;

    for(ll i = 0;i<=DIM2-1;++i){
        for(pp to:V[i]){
            mx[to.sc] = min(mx[to.sc],to.fi);
        }
    }
    ll val = 0;
    forn(i,n)val = max(val,mx[i]);
    for(ll i = DIM2-1;i>=0;--i){
        for(pp to:V[i]){
            val = max(val,to.fi);
        }
        res = min(res,val+i);
        if (val+i==1){
            ll h;
            ++h;
        }
    }
    cout<<min(ans,res)<<endl;



    return 0;
}