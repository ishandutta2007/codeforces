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

const ll DIM = 1E5+7;
const ll MOD = 1e9+123;

const ll INF = 1E17;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
ll A[DIM],pref[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,d,m;
    cin>>n>>d>>m;
    ++d;
    forn(i,n)cin>>A[i];
    sort(A+1,A+1+n,greater<ll>());
    for(ll i = 1;i<=n;++i)pref[i] = pref[i-1]+A[i];
    ll res = pref[n/d+ll((n%d)!=0)];
    ll s = 0;
    ll i = 1;
    while(A[i]>m)++i;
    ll st = i-1;
    for(;i<=n;++i){
        s+=A[i];
        res = max(res,s+pref[min(st,(n-i+st)/d+ll(((n-i+st)%d)!=0))]);
    }
    cout<<res<<endl;
    return 0;
}