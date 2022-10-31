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

const ll DIM = 5000+7;
const ll INF = 1E17;
const ll MAXN = 1E6;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
ll A[DIM];
ll solve(ll l,ll r){
    ll mi = INF;
    for(ll i = l;i<=r;++i){
        mi = min(mi,A[i]);
    }
    ll rr = mi;
    ll last = l;

    for(ll i = l;i<=r;++i){
        A[i]-=mi;
        if (A[i]==0){
            if (last<=i-1)rr+=solve(last,i-1);
            last = i+1;
        }
    }
    if (last<=r)rr+=solve(last,r);
    return min(rr,r-l+1);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    forn(i,n)cin>>A[i];
    cout<<solve(1,n)<<endl;
    return 0;
}