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
//#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 25+7;
const ll MOD = 1e9+7;

const ll INF = 1E17;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
ll A[DIM][DIM];
ll n;
ll mi(ll x,ll y){
    ll ret = A[x][y];
    while(x<n){
        ++x;
        ret+=A[x][y];
    }
    while(y<n){
        ++y;
        ret+=A[x][y];
    }
    return ret;
}
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    A[n][n] = 0;
   for(ll i = n-1;i>=1;--i){
        for(ll j = n-1;j>=1;--j){
            ll s1 = 0;
            pp pos=  {i,j+1};
            while(pos!=pp{n,n}){
                s1+=A[pos.fi][pos.sc];
                if (pos.fi==n)++pos.sc;
                else ++pos.fi;
            }
            ll s2 = 0;
            pos = {i+1,j};
            while(pos!=pp{n,n}){
                s2+=A[pos.fi][pos.sc];
                if (pos.sc==n)++pos.fi;
                else ++pos.sc;
            }
            ll dif = s2-s1+1;
            A[i][j+1] = dif;
        }
   }
   forn(i,n){
        forn(j,n)cout<<A[i][j]<<' ';
        cout<<endl;
   }
   ll q;
   cin>>q;

   while(q--){
        ll x;
        cin>>x;
        pp pos = {1,1};
         ll ss = 0;
        while(1){
            cout<<pos.fi<<' '<<pos.sc<<endl;
            ss+=A[pos.fi][pos.sc];

            if (pos==pp{n,n})break;
            if (mi(pos.fi,pos.sc+1)+ss<=x && pos.sc<n)++pos.sc;
            else ++pos.fi;
        }
   }


    return 0;
}