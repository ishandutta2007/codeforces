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

const ll DIM = 1E6+7;
const ll INF = 1E17;

int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
struct node{
    ll val,r1,r2,r3;
};
ll dp[DIM][3];
ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,r1,r2,r3,d;
    cin>>n>>r1>>r2>>r3>>d;
    forn(i,n)cin>>A[i];
    dp[0][0] = -d;
    dp[0][1] = dp[0][2] = INF;
    forn(i,n){
        dp[i][0] = min(dp[i-1][0],min(dp[i-1][1]-(d*(i==n)),dp[i-1][2]))+d;
        ll ct = A[i]*r1+r3;
        dp[i][0]+=ct;
        ll ct1 = A[i]*r1+r1*2;
        dp[i][1] = min(dp[i-1][0],dp[i-1][2])+d;
        dp[i][1]+=min(ct1,r2+r1)+d*2;

        dp[i][2] = dp[i-1][1]+d+min(ct1,r1+r2);
    }
    cout<<min(dp[n][1],min(dp[n][0],dp[n][2]))<<endl;
   // cout<<dp[n][0]<<endl<<dp[n][1]<<endl<<dp[n][2]<<endl;
    return 0;
}