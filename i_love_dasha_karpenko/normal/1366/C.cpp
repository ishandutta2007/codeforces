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

const ll DIM = 3000+7;
const ll INF = 1E10;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll sum[2][DIM*2];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        forn(i,n){
            forn(j,m){
                ll x;
                cin>>x;
                ++sum[x][i+j-1];
            }
        }
        ll res = 0;
        forn(i,(n+m-1)/2){
            ll ss1 = sum[0][i]+sum[0][n+m-i];
            ll ss2 = sum[1][i]+sum[1][n+m-i];
            res+=min(ss1,ss2);
        }

        forn(i,n+m)sum[1][i] = sum[0][i] = 0;
        cout<<res<<endl;
    }
    return 0;
}