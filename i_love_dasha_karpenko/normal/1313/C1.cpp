#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
typedef double ld;
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
const ll DIM = 1E3+7;
const ll INF = 10E17;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll pref[DIM],A[DIM],suf[DIM],T[DIM],cnt[DIM],val[DIM];
map<ll,ll> M;
void add(ll pos,ll val){
    pos = M[pos];

    for(ll i = pos;i<DIM;i+=(i&-i)){
        T[i]=max(T[i],val);
    }
}
ll get(ll pos){
    pos = M[pos];
    ll ret = 0;
    for(ll i = pos;i>0;i-=(i&-i)){
            ret = max(ret,T[i]);
    }
    return ret;
}
void addmi(ll pos,ll val){
    pos = M[pos];

    for(ll i = pos;i<DIM;i+=(i&-i)){
        T[i]=min(T[i],val);
    }
}
ll getmi(ll pos){
    pos = M[pos];
    ll ret = INF;
    for(ll i = pos;i>0;i-=(i&-i)){
            ret = min(ret,T[i]);
    }
    return ret;
}
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    set<ll> S;
    forn(i,n){
        cin>>A[i];
        S.insert(A[i]);
    }
    ll po = 1;
    for(ll to:S){
        M[to] = po++;
    }
    ll mx = INF;
    ll r = 0;
    forn(i,n){
        ll pos = get(A[i]);
        pref[i] = pref[pos]+(i-pos)*A[i];
        add(A[i],i);
    }

    r = 0;
    mx = INF;
    for(ll i = 0;i<DIM;i++)T[i] = n+1;
    ll res =0 ,pst = 0;
    for(ll i = n;i>=1;i--){
        ll pos = getmi(A[i]);

        suf[i] = suf[pos]+(pos-i)*A[i];
        addmi(A[i],i);
        if (res<suf[i]+pref[i-1]){
            pst = i;
            res = suf[i]+pref[i-1];
        }
    }
    ll pos = pst;
    if (pref[n]>res){
        res = pref[n];
        pos = n+1;
    }
    mx = INF;
    for(ll i = pos-1;i>=1;i--){
        mx = min(mx,A[i]);
        val[i] = mx;
    }
    mx = INF;
    for(ll i = pos;i<=n;i++){
        mx = min(mx,A[i]);
        val[i] = mx;
    }
    forn(i,n){
        cout<<val[i]<<' ';
    }

    return 0;
}
// a[i]-b[i]>b[j]-a[j]