#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

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
const ll INF = 1E19;
const ll MAXN = 1E6;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
ll A[DIM],dp[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){

        ll n,k;
        cin>>n>>k;
        forn(i,n){
            cin>>A[i];
        }
        forn(j,n){
            ll x;

            cin>>x;
        }
        sort(A+1,A+1+n);
        ll res =0 ;
        forn(i,n){
            ll pos = lower_bound(A+1,A+1+n,A[i]-k)-A;
            --pos;
            dp[i] = max(dp[i-1],i-pos);
            res = max(i-pos+dp[pos],res);
        }
        cout<<res<<endl;

    }
    return 0;
}