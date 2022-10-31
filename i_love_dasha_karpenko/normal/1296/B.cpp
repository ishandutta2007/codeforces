#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
//template<typename TN>
//typedef tree<TN,null_type,less<TN>,rb_tree_tag,tree_order_statistics_node_update> super_set<TN>;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 2*10E2 +7;
const ll INF = 10E17;
const ll MAXN = 10E5;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    forn(qe,t){
        ll n;
        cin>>n;
        ll x = n;
        ll r = 1;
        while(x>0){
            r*=10;
            x/=10;
        }
        r/=10;
        ll res = n;
        while(n>=10){
            while(n>=r){
                ll g = n/r;
                g*=r;
                g/=10;
                res+=g;
                n%=r;
                n+=g;
            }
            r/=10;
        }
        cout<<res<<endl;
    }
    return 0;
}