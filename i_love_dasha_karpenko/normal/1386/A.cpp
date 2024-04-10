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

const ll DIM = 2E4+7;
const ll MOD = 1e9+7;
const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
map<ll,ll> an;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        an.clear();
        ll n;
        cin>>n;
        vector<ll> wc;
        ll l = 1,r = n;
        while(l!=r){
            ll tm = (l+r)/2;
            wc.pb(tm);
            if (tm+1==r)break;
            l = tm;
        }
        reverse(wc.begin(),wc.end());
        ll pos = 1;
        ll flag = 0;
        for(ll to:wc){
            if (flag==0)pos+=to;
            else pos-=to;
            flag^=1;
        }
        l = 1;r = n;
        cout<<"? "<<pos<<endl;
        set<ll> S;
        S.insert(pos);
        ll q;
        cin>>q;
        while(l!=r){
            ll tm = (l+r)/2;
            if (an.count(tm)==1){
                if (an[tm])r = tm;
                else {
                    l = tm;
                    if (tm+1==r)l = tm+1;
                }
                continue;
            }
            if (pos+tm<=n && S.count(pos+tm)==0)pos+=tm;
            else pos-=tm;
            S.insert(pos);
            cout<<"? "<<pos<<endl;

            cin>>q;
            an[tm] = q;
            if (q==0){
                l = tm;
                if (tm+1==r)l = tm+1;
            }
            else{
                r = tm;
            }
        }
        cout<<"= "<<l<<endl;

    }
    return 0;
}