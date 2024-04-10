#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long  ll;
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

const ll DIM = 1E5+7;
const ll DIM2 = 1E6+7;
const ll INF = 1E17;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
const ll masksz = po(11)-1;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}


ll ask(ll p1,ll p2){
    cout<<"? "<<p1<<' '<<p2;
    cout<<endl;
    ll ret;
    cin>>ret;
    return ret;
}
ll ans[DIM];
ll bit[12];
ll vis[12];
ll n;
void init(){
    forn(i,90){
        ll a = getInt()%n+1;
        ll b = getInt()%n+1;
        while (a==b){
            b = getInt()%n+1;
        }
        ll num = ask(a,b);
        ll cur = 0;
        forn(j,11){
            if (num%2==0)bit[cur] = a;
            num/=2;
            ++cur;
        }
    }
}
ll getnum(ll pos){
    ll ret = masksz;
    for(ll i = 0;i<11;++i){
        if (vis[i]==1){
            ll num = masksz^po(i);
            ret = (ret&num);
            continue;
        }
        if (bit[i]==pos){
            ll num = masksz^po(i);
            ret = (ret&num);
        }
        else{
            ll num = ask(bit[i],pos);

            ret = (ret&num);
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;


    init();
    ans[1] = getnum(1);
    ll x = ans[1];
    ll mult = 1;
    for(ll i = 0;i<11;++i){
        if (!(ans[1]&mult))vis[i] = 1;
        mult*=2;
    }
    ll last = 1;
    for(ll i = 2;i<=n;++i){
        ll num = ask(last,i);
        if (num==ans[last]){
            last = i;
            ans[last] = getnum(last);
            mult = 1;
            for(ll i = 0;i<11;++i){
                if (!(mult&ans[last]))vis[i] = 1;
                mult*=2;
            }
        }
    }
    forn(i,n){
        if (i==last)continue;
        ans[i] = ask(last,i);
    }
    cout<<"! ";
    forn(i,n)cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}