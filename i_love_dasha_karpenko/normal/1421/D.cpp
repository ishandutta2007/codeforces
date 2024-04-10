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
ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll xc,yc;
        cin>>yc>>xc;
        forn(i,6)cin>>A[i];
        while(1){
            ll flag = 0;
            ll r[7];
            r[1] = A[2]+A[6];
            r[2] = A[1]+A[3];
            r[3] = A[2]+A[4];
            r[4] = A[3]+A[5];
            r[5] = A[4]+A[6];
            r[6] = A[1]+A[5];
            forn(i,6){
                if (A[i]>r[i]){
                    A[i] = r[i];
                    flag = 1;
                }
            }
            if (flag==0)break;
        }

        pp x = {A[5],A[2]};
        pp y = {A[3],A[6]};
        pp z = {A[4],A[1]};
        ll res = max(0ll,xc)*x.sc+max(0ll,-xc)*x.fi+max(0ll,yc)*y.sc+max(0ll,-yc)*y.fi;
        if (xc>0 && yc>0){
            ll m = min(xc,yc);
            xc-=m;
            yc-=m;
            ll r = m*z.sc+max(0ll,xc)*x.sc+max(0ll,-xc)*x.fi+max(0ll,yc)*y.sc+max(0ll,-yc)*y.fi;
            xc+=m;
            yc+=m;
            res = min(res,r);
        }
        if (xc<0 && yc<0){
            ll m = min(-xc,-yc);
            xc+=m;
            yc+=m;
            ll r = m*z.fi+max(0ll,xc)*x.sc+max(0ll,-xc)*x.fi+max(0ll,yc)*y.sc+max(0ll,-yc)*y.fi;
            xc-=m;
            yc-=m;
            res = min(res,r);
        }
        cout<<res<<endl;
    }
    return 0;
}