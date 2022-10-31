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
//#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2*10E4+7;
const ll INF = 10E16;
const ll MAXN = 10E8;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
ll n;
ll A[DIM],vis[DIM],res = INF;
void check(ll val){
    ll cnt = 0;
    forn(i,n){
        ll g =val-A[i]%val;
        if (A[i]>=val)g = min(g,A[i]%val);
        cnt+=g;
    }
    res = min(res,cnt);
}
set<ll> S;
void addprimes(ll x){
    for(ll i = 2;i<=sqrt(x);i++){
        if (x%i==0)S.insert(i);
        while(x%i==0)x/=i;
    }
    if (x!=1)S.insert(x);
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    cin>>n;
    forn(i,n)cin>>A[i];
    shuffle(A+1,A+1+n,mt);
    forn(i,min(50ll,n)){
        addprimes(A[i]);
        addprimes(A[i]+1);
        if (A[i]>1)
        addprimes(A[i]-1);
    }
    for(ll to:S)check(to);
    cout<<res<<endl;
    return 0;
}