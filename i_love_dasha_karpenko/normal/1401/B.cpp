#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less_equal<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 300+7;
const ll MOD = 1e9+123;
const ll M1 = 1e9+7;
const ll INF = 1E17;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){//
        ll x,y,z;
        cin>>x>>y>>z;
        ll x1,y1,z1;
        cin>>x1>>y1>>z1;
        ll res = 0;
        ll g = min(x,z1);
        z1-=g;
        x-=g;
        g = min(x1,y);
        y-=g;
        x1-=g;
        if (z1<y){
            ll g = min(z,z1);
            z1-=g;
            z-=g;
        }
        else{
            ll g = min(y,y1);
            y-=g;
            y1-=g;
        }
        res=-min(z1,y)*2+min(z,y1)*2;
        cout<<res<<endl;
    }
    return 0;
}