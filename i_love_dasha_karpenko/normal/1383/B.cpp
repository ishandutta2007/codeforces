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
const ll MOD = 1e9+7;

const ll INF = 1E13;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
const ll mxbit = 33;
ll n,cnt[mxbit+7];
void solve(){
    memset(cnt,0,sizeof(cnt));
    cin>>n;
    forn(i,n){
        ll x;
        cin>>x;
        ll pos = 0;
        while(x>0){
            cnt[pos]+=x%2;
            x/=2;
            ++pos;
        }
    }
    for(ll i = mxbit;i>=0;--i){
        if (cnt[i]%2==0)continue;
        if ((cnt[i]-1)%4==0 || (n-cnt[i])%2==1){
            cout<<"WIN\n";
            return;
        }
        else{
            cout<<"LOSE\n";
            return;
        }

    }
    cout<<"DRAW\n";

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}