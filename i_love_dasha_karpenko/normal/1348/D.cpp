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
#define po(x) ((unsigned long long)(1)<<x)
const ll DIM = 500+7;
const ll INF = 10E17;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        n--;
        if (n==1){
            cout<<"1\n0\n";
            continue;
        }
        ll mult = 2;
        vector<ll> ans;
        while(n>0){
            if (n<=mult*2){
                if (n<=mult){
                    ans.pb(n-mult/2);
                    break;
                }
                n-=mult;
                if (n<=mult)
                ans.pb(n/2);
                ans.pb(n%2);
                break;
            }
            n-=mult;
            ans.pb(mult/2);
            mult*=2;
        }
        cout<<ans.size()<<endl;
        for(ll to:ans)cout<<to<<' ';
        cout<<endl;
    }
    return 0;
}