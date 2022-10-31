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
const ll DIM = 2E5+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3,greater<ll>());
        ll res = 0;
        if (a[0]>=1){
            a[0]--;
            res++;
        }
        if (a[1]>=1){
            a[1]--;
            res++;
        }
        if (a[2]>=1){
            a[2]--;
            res++;
        }
        if (a[2]>=1 && a[0]>=1){
            a[2]--;
            a[0]--;
            res++;
        }
        if (a[1]>=1 && a[0]>=1){
            a[1]--;
            a[0]--;
            res++;
        }
        if (a[1]>=1 && a[2]>=1){
            res++;
            a[1]--;
            a[2]--;
        }
        if (a[1]>0 && a[0]>0 && a[2]>0)res++;
        cout<<res<<endl;
    }
    return 0;
}
// a[i]-b[i]>b[j]-a[j]