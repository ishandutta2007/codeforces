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
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E5+7;
const ll DIM2 = 1E4+7;
const ll INF = 1E17;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}


ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        forn(i,n){
            cin>>A[i];
        }
        vector<ll> ans;
        ans.pb(A[1]);
        ans.pb(A[2]);
        ll dif = 0;
        for(ll i = 3;i<=n;++i){
            if ((A[i]>A[i-1] && A[i-1]>A[i-2]) || (A[i]<A[i-1] && A[i-1]<A[i-2])){
                ans.pop_back();
            }
            ans.pb(A[i]);
        }
        cout<<ans.size()<<endl;
        for(ll to:ans)cout<<to<<' ';
        cout<<endl;
    }
    return 0;
}