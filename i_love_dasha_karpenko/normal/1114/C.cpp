#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 3*10E4 +7;
const ll INF = 10E17;

ll n,b;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>b;
    ll res = INF;

    for(ll i = 2;i<=sqrt(b);i++){
        if (b%i!=0)continue;
        ll cnt = 0,need = 0;
        while(b%i==0){
            need++;
            b/=i;
        }
        ll x = n;
        while(x>0){
            cnt+=x/i;
            x/=i;
        }
        cnt/=need;
        res = min(res,cnt);
    }
    if (b>1){
        ll i = b;
        ll cnt = 0,need = 0;
        while(b%i==0){
            need++;
            b/=i;
        }
        ll x = n;
        while(x>0){
            cnt+=x/i;
            x/=i;
        }
        cnt/=need;
        res = min(res,cnt);
    }
    cout<<res<<endl;
    return 0;
}