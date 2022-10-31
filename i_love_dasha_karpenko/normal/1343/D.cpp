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
const ll DIM = 4E5+7;
const ll INF = 1e19;

ll A[DIM],mx[DIM],sum[DIM],mi[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        forn(i,n)cin>>A[i];
        for(ll i = 1;i<=n/2;++i){
            sum[A[i]+A[n-i+1]]++;
            mx[max(A[i],A[n-i+1])]++;
            mi[min(A[i],A[n-i+1])]++;
        }
        forn(i,k){
            mx[i]+=mx[i-1];
        }
        for(ll i = k;i>=1;--i){
            mi[i]+=mi[i+1];
        }
        ll res = INF;
        forn(i,k*2){
            ll g = n/2-sum[i];
            ll r = 0;
            g-=mi[i];
            r+=mi[i]*2;
            g-=mx[max(0ll,i-k-1)];
            r+=mx[max(0ll,i-k-1)]*2;
            r+=g;
            res = min(res,r);

        }
        cout<<res<<endl;
        forn(i,k*2)mi[i] = mx[i] = sum[i] = 0;
    }
    return 0;
}