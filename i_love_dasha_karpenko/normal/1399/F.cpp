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

const ll DIM = 3000+7;
const ll DIM1 = 2E5+7;
const ll MOD = 1e9+7;

const ll INF = 1E8;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
ll PS[DIM1];
pp A[DIM],tmp[DIM];
ll cnt[DIM];
vector<pp> V[DIM*2],vv[DIM*2];
ll dp[DIM*2];
ll d[DIM*2];
bool mc(pp a,pp b){
    return a.sc-a.fi<b.sc-b.fi;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        set<ll> S;
        forn(i,n){
            cin>>A[i].fi>>A[i].sc;
            S.insert(A[i].fi);
            S.insert(A[i].sc);
        }
        ll ptr = 0;
        for(ll to:S){
            PS[to] = ++ptr;
        }
        forn(i,n){
            A[i].fi = PS[A[i].fi];
            A[i].sc = PS[A[i].sc];
        }
        sort(A+1,A+1+n,mc);
        ll bpr = ptr;
        forn(i,n){
            vector<ll> V;
            forn(j,n){
                if (A[i].fi<=A[j].fi && A[j].sc<=A[i].sc && i!=j)V.pb(j);
            }
            S.clear();
            for(ll to:V){
                S.insert(A[to].fi);
                S.insert(A[to].sc);
            }
            ptr = 0;
            for(ll to:S)PS[to] = ++ptr;
            for(ll to:V){
                tmp[to] = {PS[A[to].fi],PS[A[to].sc]};
                vv[tmp[to].sc].pb({tmp[to].fi,cnt[to]});
            }
            forn(i,ptr){
                d[i] = 0;
                for(pp to:vv[i]){
                    d[i] = max(d[i],d[to.fi-1]+to.sc);
                }
                d[i] = max(d[i],d[i-1]);
            }
            cnt[i] = d[ptr]+1;
            forn(i,ptr){
                vv[i].clear();
            }


        }
        ptr = bpr;

        forn(i,n){

            V[A[i].sc].pb({A[i].fi,cnt[i]});
        }
        forn(i,ptr)dp[i] = -INF;

        dp[0] = 0;
        forn(i,ptr){
            for(pp to:V[i]){
                dp[i] = max(dp[i],dp[to.fi-1]+to.sc);
            }
            dp[i] = max(dp[i],dp[i-1]);
        }
        cout<<dp[ptr]<<endl;
        forn(i,ptr){
            V[i].clear();
            dp[i] = 0;
        }
        forn(i,n)cnt[i] = 0;

    }

    return 0;
}