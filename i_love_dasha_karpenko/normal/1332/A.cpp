#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
typedef double ld;
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
const ll DIM = 2E5+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
//

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll x,y,x1,y1,x2,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        if (!(x1<=x && x<=x2 && y1<=y && y<=y2)){
            cout<<"No\n";
            continue;
        }
        x-=a;
        x+=b;
        y-=c;
        y+=d;
        if (!(x1<=x && x<=x2 && y1<=y && y<=y2)){
            cout<<"No\n";
            continue;
        }
        if ((a+b!=0 && x1==x2) || (c+d!=0 && y1==y2)){
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";
    }
    return 0;
}