#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int  ll;
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

const ll DIM = 5E5+7;
const ll INF = 1E10;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

const ll lim = 1E7;
ll prime[lim+7],ans[2][DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    prime[1] = 1;
    for(ll i = 2;i<=lim;++i){
        if (prime[i]!=0)continue;
        prime[i] = i;
        for(long long j = (long long)(i)*i;j<=lim;j+=i)prime[j] = i;
    }
    ll n;
    cin>>n;
    forn(i,n){
        ll x;
        cin>>x;
        ll f = 1;

            ll pr = prime[x];
            while(x%pr==0){
                x/=pr;
                f*=pr;
            }


        if (x==1 || f==1){
            ans[0][i] = ans[1][i] = -1;
        }
        else{
            ans[0][i] = x;
            ans[1][i] = f;
        }
    }
    forn(i,n)cout<<ans[0][i]<<' ';
    cout<<endl;
    forn(i,n)cout<<ans[1][i]<<' ';
    cout<<endl;
    return 0;
}