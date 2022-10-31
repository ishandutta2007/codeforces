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
const ll DIM = 100+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll A[DIM][DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        memset(A,0,sizeof(A));
        cin>>n;
        ll cnt1 = 0,cnt2 = 0;
        forn(i,n){
            ll x;
            cin>>x;
            if (x%2==0)cnt1++;
            else cnt2++;
        }
        if (cnt1!=0 && cnt2!=0)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}