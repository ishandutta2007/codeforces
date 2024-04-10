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

const ll DIM = 2E5+7;
const ll INF = 2E15;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM],B[DIM],dp[DIM],mi[DIM];
ll n,k;
ll F(ll val){
    forn(i,n){
        if (i>=2)
        dp[i] = mi[i-2]+(A[i]<=val);
        else dp[i] = (A[i]<=val);
        mi[i] = max(dp[i],dp[i-1]);
    }
    ll num = k/2+k%2;
    if (k%2==0){
        if (dp[n-1]>=num || dp[n-2]>=num)return 1;
    }
    else{
        if (dp[n]>=num || dp[n-1]>=num)return 1;
    }
    dp[1] = 0;
    for(ll i = 2;i<=n;++i){
        if (i>=3)
        dp[i-1] = mi[i-3]+(A[i]<=val);
        else dp[i-1] = (A[i]<=val);
        mi[i-1] = max(dp[i-1],dp[i-2]);
    }
    num = k/2;
    if (k%2!=0){
        if (dp[n-2]>=num || dp[n-3]>=num)return 1;
    }
    else{
        if (dp[n-1]>=num || dp[n-2]>=num)return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    forn(i,n){
        cin>>A[i];
        B[i] = A[i];
    }
    sort(B+1,B+1+n);
    ll l = 1,r = n;
    while(l!=r){
        ll tm = (l+r)/2;
        if (F(B[tm]))r = tm;
        else l = tm+1;
    }
    cout<<B[l]<<endl;
    return 0;
}
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,