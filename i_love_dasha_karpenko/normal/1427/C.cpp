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

const ll DIM = 1E6+7;

const ll MOD = 1e9+7;

const ll INF = 1E18+70;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}

struct node{
    ll fi,sc,th;
};
node A[DIM];
ll dp[DIM],pref[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll r,n;
    cin>>r>>n;
    ll mx = 0;
    A[0] = {0,1,1};
    forn(i,n){
        cin>>A[i].fi>>A[i].sc>>A[i].th;
        dp[i] = -INF;
        for(ll j = i-1;j>=0;--j){

            if (A[i].fi-A[j].fi>=r*2){
                dp[i]  =max(dp[i],pref[j]+1);
                break;
            }
            else if (A[i].fi-A[j].fi>=abs(A[i].sc-A[j].sc)+abs(A[j].th-A[i].th)){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        pref[i] = max(dp[i],pref[i-1]);
    }
    cout<<pref[n]<<endl;


    return 0;

}