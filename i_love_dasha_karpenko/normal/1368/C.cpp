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

const ll DIM = 2E5+7;
const ll INF = 2E15;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;

    vector<pp> ans;
    ans.pb({0,0});
    ans.pb({0,1});
    ans.pb({1,0});
    ans.pb({1,1});
    ans.pb({1,2});
    ans.pb({2,1});
    ans.pb({2,2});
    ll cur = 2;
   // n--;
    while(--n){
        ans.pb({cur,cur+1});
        ans.pb({cur+1,cur});
        ++cur;
        ans.pb({cur,cur});
    }
    cout<<ans.size()<<endl;
    for(pp to:ans)cout<<to.fi<<' '<<to.sc<<endl;
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