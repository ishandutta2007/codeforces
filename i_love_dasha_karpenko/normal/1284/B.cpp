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
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 20+7;
const ll INF = 10E10;
vector<pp> V;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    ll res = 0,cnt = 0;
    forn(i,n){
        ll mi = INF;
        ll l,flag =0; cin>>l;
        ll mx = 0;
        forn(j,l){
            ll x; cin>>x;
            if (x>mi)flag = 1;
            mi = min(mi,x);
            mx = max(mx,x);
        }
        if (flag==1){res+=(n-cnt)*2-1;cnt++;}
        else V.pb({mi,mx});
    }
    //cout<<V.size()<<endl;
    sort(V.begin(),V.end());
    for(pp to:V){
        ll pos = (lower_bound(V.begin(),V.end(),pp{to.sc-1,INF})-V.begin());
        res+=pos;
        //.cout<<pos<<endl;
    }
    cout<<res<<endl;
    return 0;
}