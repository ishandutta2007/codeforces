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
//#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 3000+7;
const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll vv[DIM],vis[DIM];
ll n;
ll F(ll x){
    return n-x+1-(n/x)-(n%x!=0);
}
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin>>n;
    if (n<=3){
        cout<<0<<endl;
        return 0;
    }
    ll mx = 2;
    for(ll i = 2;i<=n;++i){
        if (F(mx)<F(i))mx = i;
    }
    ll cnt = 0;
    forn(i,n)vv[i] = 1;
    for(ll i = 1;i<=n;i+=mx){
        vv[i] = 0;
    }
    while(1){

        vector<ll> ask;
        forn(i,n){
            if (vv[i]==1 && vis[i]==0){
                vis[i] = 1;
                ask.pb(i);
            }
            if (ask.size()==mx)break;
        }
        if (ask.size()<mx)break;
        cout<<ask.size()<<' ';
        for(ll to:ask)cout<<to<<' ';
        cout<<endl;
        ll x;
        cin>>x;
        forn(i,mx){
            vis[x] = 0;
            x++;
            if (x>n)x = 1;
        }
    }
    cout<<0<<endl;
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