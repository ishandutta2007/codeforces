#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 10E4 +7;
const ll INF = 10E17+7;
ll x;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x; cin>>x;
    ll sq = sqrt(x);
    pp ans = {INF,INF};
    for(ll i = 1;i<=sq;i++){
        if (x%i==0 && __gcd(i,x/i)==1 && max(ans.fi,ans.sc)>max(i,x/i)){
            ans.fi = i;
            ans.sc = x/i;
        }
    }
    cout<<ans.fi<<' '<<ans.sc<<endl;
    return 0;
}