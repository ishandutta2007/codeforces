#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 200  +7;

const ll MOD = 1e9+7;

const ll INF = 1E18+70;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
ll A[DIM][DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        pp start,finish;
        forn(i,n){
            forn(j,n){
                char ch;
                cin>>ch;
                if (ch=='1')A[i][j] = 1;
                else A[i][j] = 0;
            }
        }
        vector<pp> ans;
        if (A[1][2]==A[2][1]){
            ll val = A[1][2];
            if (A[n-1][n]==val)ans.pb({n-1,n});
            if (A[n][n-1]==val)ans.pb({n,n-1});
        }
        else if (A[n][n-1]==A[n-1][n]){
            ll val = A[n][n-1];
            if (A[1][2]==val)ans.pb({1,2});
            if (A[2][1]==val)ans.pb({2,1});
        }
        else{
            ans.pb({1,2});
            ll val = A[2][1];
            if (A[n-1][n]==val)ans.pb({n-1,n});
            if (A[n][n-1]==val)ans.pb({n,n-1});
        }
        cout<<ans.size()<<endl;
        for(pp to:ans)cout<<to.fi<<' '<<to.sc<<endl;

    }
    return 0;
}