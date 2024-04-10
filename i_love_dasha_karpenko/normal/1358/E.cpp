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

const ll DIM = 5E5+7;
const ll INF = 1E17;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM],mi[DIM],mas[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll mid = n/2+n%2;

    forn(i,mid)cin>>A[i];
    ll x;
    cin>>x;
    mi[0] = 0;
    forn(i,mid){
        mas[i] = mas[i-1]+x-A[i];
    }
    forn(i,mid){
        mi[i] = min(mi[i-1],mas[i]);
    }
    for(ll i = mid+1;i<=n;++i)A[i] = x;
    mi[0] = 0;
    ll base = 0;
    ll cur = mid;
    forn(i,cur)base+=A[i];
    while(cur<=n){
        if (base+mi[n-cur]>0){
            cout<<cur<<endl;
            return 0;
        }
        base+=A[++cur];
    }
    cout<<"-1\n";

    return 0;
}