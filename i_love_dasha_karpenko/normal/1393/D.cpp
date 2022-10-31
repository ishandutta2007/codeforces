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

const ll DIM = 2000+7;
const ll MOD = 1e9+7;
const ll INF = 1E17;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
ll gi(char ch){
    return ch-'a'+1;
}
ll A[DIM][DIM],dp[2][DIM][DIM],dp1[2][DIM][DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,m;
    cin>>n>>m;
    forn(i,n){
        forn(j,m){
            char ch;
            cin>>ch;
            A[i][j] = gi(ch);
        }
    }
    forn(i,n){
        forn(j,m){
            if (A[i][j]==A[i-1][j])dp[0][i][j] = dp[0][i-1][j]+1;
            else dp[0][i][j] = 1;
        }
    }
    for(ll i = n;i>=1;--i){
        forn(j,m){
            if (A[i][j]==A[i+1][j])dp[1][i][j] = dp[1][i+1][j]+1;
            else dp[1][i][j] = 1;
        }
    }
    forn(i,n){
        forn(j,m){
            if (A[i][j]==A[i][j-1])dp1[0][i][j] = min(dp1[0][i][j-1]+1,min(dp[1][i][j],dp[0][i][j]));
            else dp1[0][i][j] = 1;
        }
    }
    ll res = 0;
    forn(i,n){
        for(ll j = m;j>=1;--j){
            if (A[i][j]==A[i][j+1])dp1[1][i][j] = min(dp1[1][i][j+1]+1,min(dp[1][i][j],dp[0][i][j]));
            else dp1[1][i][j] = 1;
            res+=min(dp1[1][i][j],dp1[0][i][j]);
        }
    }
    cout<<res<<endl;
    return 0;
}