#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E5+7;
const ll INF = 1e18;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll trio = n/3+1-(n%3==0);
        ll cnt = 0;
        ll cur = 1;
        while(cnt+cur<trio){
            cnt+=cur;

            cur*=4;
        }
        ll num1 = trio-cnt+cur-1;
        ll order = trio-cnt-1;
        ll num2 = cur*2;
        ll mult = 1;
        while(order>0){
            ll g = order%4;
            if(g==1)num2+=2*mult;
            if (g==2)num2+=3*mult;
            if (g==3)num2+=mult;
            mult*=4;
            order/=4;
        }
        if (n%3==0)cout<<(num1^num2)<<endl;
        if (n%3==1)cout<<num1<<endl;
        if (n%3==2)cout<<num2<<endl;
    }
    return 0;
}