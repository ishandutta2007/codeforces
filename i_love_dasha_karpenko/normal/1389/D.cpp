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
const ll MOD = 1e9+7;
const ll INF = 1E17;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        ll to_m = 0;
        ll bi = 0;
        if (l1>r2 || l2>r1){
            to_m = max(l1-r2,l2-r1);
        }
        else{
            if (l1<=l2 && r2<=r1)bi = r2-l2;
            else if (l2<=l1 && r1<=r2)bi =r1-l1;
            else bi = min(r2-l1,r1-l2);
        }
        ll res = INF;
        k-=n*bi;
        if (k<=0){
            cout<<0<<endl;
            continue;
        }
        ll l = min(l1,l2),r = max(r1,r2);
        ll len = r-l;
        forn(i,n){
            ll rr = i*to_m;
            ll s1 = i*(len-bi);
            ll g = min(s1,k);
            rr+=g;

            rr+=(k-g)*2;
            res = min(res,rr);
        }
        cout<<res<<endl;
    }


    return 0;
}