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
const ll DIM = 30+7;
const ll INF = 10E17;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll  power[80];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll mx = 0;
        forn(i,n){
            ll x;
            cin>>x;
            ll cur = 0;
            while(x>0){
                power[cur]+=x%k;
                x/=k;
                cur++;
            }
            mx = max(mx,cur-1);
        }
        for(ll i = mx;i>0;i--){
            if (power[i]>i+1){
                power[0] = INF;
                break;
            }

            if (power[i]>1){
                power[i-1]+=(power[i]-1)*k;
                power[i] = 1;
            }
        }
        if (power[0]>1){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
        for(ll i=0;i<=mx;i++)power[i] = 0;
    }
    return 0;
}