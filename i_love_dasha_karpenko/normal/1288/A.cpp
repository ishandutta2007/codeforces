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
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 5000+7;
const ll INF = 10E17;
ll to_up(ll x,ll y){
    return x/y+(x%y!=0?1:0);
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(qer,t){
        ll n,d; cin>>n>>d;
        ll sq = sqrt(d);
        ll res = d;
        forn(i,sq){
            res = min(res,to_up(d,i)+i-1);
            ll q = res/i;
            res = min(res,to_up(d,q)+q-1);
        }
        if (res<=n)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}