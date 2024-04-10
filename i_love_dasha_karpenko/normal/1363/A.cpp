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
const ll DIM = 1E6+7;
const ll INF = 1E16;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll cnt = 0;
        forn(i,n){
            ll l;
            cin>>l;
            if (l%2)cnt++;
        }
        ll ta = n-cnt;
        ll r= 0;
        if (cnt>0){
            cnt--;
            r = 1;
        }
        if (r==0){
            cout<<"No\n";
            continue;
        }
        cnt/=2;
        x--;
        ll g = min(cnt,x/2);
        x-=g*2;
        cnt-=g;
        if (ta>=x){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}