#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
#define x1 dsfdsfes
#define y1 sfsdfdse
#define po(x) (1ll<<x)
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 1000+7;
const ll INF = 10E17;


int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(qi,t){
        ll n;
        cin>>n;
        ll a,b,c;
        a=b=c=-1;
        ll sq = sqrt(n);
        for(ll i = 2;i<=sq;i++){
            if (n%i==0 && n/i!=i){
                ll sq1 = sqrt(n/i);
                for(ll j = 2;j<=sq1;j++){
                    if ((n/i)%j==0 && n/i/j!=i && n/i/j!=j && i!=j){
                        a = i;
                        b = j;
                        c = n/i/j;
                    }
                }
            }
        }
        if (a!=-1)cout<<"YES\n"<<a<<' '<<b<<' '<<c<<endl;
        else cout<<"NO\n";
    }
    return 0;
}