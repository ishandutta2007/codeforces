#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E5+7;
const ll MOD = 1e9+7;
const ll INF = 1E5;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM],dp[DIM][6];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k,z;
        cin>>n>>k>>z;
        forn(i,n){
            cin>>A[i];
        }
        dp[1][0] = A[1];

        for(ll i = 2;i<=n;++i){
            for(ll j = 0;j<=z;++j){
                if (i-1+j*2>k)break;
                if (i==1 && j>0)break;
                if (j>0)
                dp[i][j] =  max(dp[i][j-1]+A[i-1]+A[i],dp[i-1][j]+A[i]);
                else dp[i][j] = dp[i-1][j]+A[i];
            }
        }
        ll mx = 0;
        forn(i,n)
        for(ll j = 0;j<=z;++j){
            mx = max(mx,dp[i][j]);
            if (j<z && i>1 && i+j*2<=k)
                mx = max(mx,dp[i][j]+A[i-1]);
            dp[i][j] = 0;
        }
        cout<<mx<<endl;

    }


    return 0;
}