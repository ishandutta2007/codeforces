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
const ll INF = 1E5;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // 4+10+14 29
    // 40 6 10 15
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if (n<31)cout<<"NO\n";
        else if (n==36)cout<<"YES\n5 6 10 15\n";
        else if (n==44)cout<<"YES\n6 7 10 21\n";
        else if (n==40)cout<<"YES\n6 10 15 9\n";
        else cout<<"YES\n6 10 14 "<<n-30<<endl;
    }

    return 0;
}