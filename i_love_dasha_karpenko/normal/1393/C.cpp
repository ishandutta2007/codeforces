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

const ll DIM = 1E5+7;
const ll MOD = 1e9+7;
const ll INF = 1E17;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
ll cnt[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        forn(i,n){
            ll x;
            cin>>x;
            ++cnt[x];
        }
        ll l = 0,r = n-2;
        while(l!=r){
            ll tm = (l+r+1)/2;
            priority_queue<ll> Q;
            for(ll i = tm+1;i<=n;i+=tm+1){
                Q.push(tm+1);
            }
            Q.push(n%(tm+1));
            ll flag = 0;

            forn(i,n){
                vector<ll> V;
                forn(j,cnt[i]){
                    if (Q.empty()){
                        flag = 1;
                        break;
                    }
                    ll t = Q.top();
                    Q.pop();
                    if (t==0){
                        flag = 1;
                        break;
                    }
                    if (t!=0)V.pb(t-1);
                }
                for(ll to:V)Q.push(to);
                if (flag)break;
            }
            if (flag)r = tm-1;
            else l = tm;
        }
        cout<<l<<endl;
        forn(i,n)cnt[i] = 0;
    }
    return 0;
}