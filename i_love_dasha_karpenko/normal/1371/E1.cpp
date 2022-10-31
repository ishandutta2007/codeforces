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

const ll DIM = 2000+7;
const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll n,p,A[DIM];
ll F(ll x){
    ll flag = 0;
    ll ptr = 0;

    forn(i,n){
        while(ptr<n && A[ptr+1]<=x)++ptr;
        if (ptr<i)return 0;
        if ((ptr-i+1)%p==0)flag = 1;
        ++x;
    }
    return flag^1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>p;
    ll mx = 1;
    forn(i,n){
        cin>>A[i];
        mx = max(mx,A[i]);
    }
    sort(A+1,A+1+n);
    vector<ll> ans;
    forn(i,mx){
        if (F(i))ans.pb(i);
    }
    cout<<ans.size()<<endl;
    for(ll to:ans)cout<<to<<' ';
    cout<<endl;
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