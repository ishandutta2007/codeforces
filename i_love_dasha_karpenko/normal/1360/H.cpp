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
const ll DIM = 100+7;
const ll INF = 1E16;
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
        ll n,m;
        cin>>n>>m;
        ll mult = 1;
        forn(j,m-1)mult*=2;
        forn(i,n){
            ll cur = mult;
            ll num = 0;
            forn(j,m){
                char x;
                cin>>x;
                num+=(x=='1')*cur;
                cur/=2;
            }
            A[i] = num;
        }
        sort(A+1,A+1+n);
        ll mid = (mult*2-n-1)/2;
        forn(i,n){
            if (A[i]<=mid)++mid;
        }
        vector<ll> ans;
        forn(xx,m){
            ans.pb(mid&1);
            mid/=2;
        }
        while(!ans.empty()){
            cout<<ans.back();
            ans.pop_back();
        }
        cout<<endl;
    }

    return 0;
}