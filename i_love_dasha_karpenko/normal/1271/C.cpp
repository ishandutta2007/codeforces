#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> satan_set;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1000+7;
const ll INF = 10e16;
const ll MOD = 998244353 ;
const ll MAXN = 1000000000;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    pp start; cin>>start.fi>>start.sc;
    ll cnt1,cnt2,cnt3,cnt4;
    cnt1=cnt2=cnt3=cnt4= 0;
    forn(i,n){
        ll x,y; cin>>x>>y;

        if (x<start.fi)cnt1++;
        else if (x>start.fi) cnt2++;

        if (y<start.sc)cnt3++;
        else if (y>start.sc)cnt4++;
    }
    if (start.fi==0)cnt1 = -1;
    if (start.fi==MAXN)cnt2 = -1;
    if (start.sc==0)cnt3 = -1;
    if (start.sc==MAXN)cnt4 = -1;
    ll m = max(max(cnt1,cnt2),max(cnt3,cnt4));
    cout<<m<<endl;
    if (cnt1==m){
        cout<<start.fi-1<<' '<<start.sc<<endl;
    }
    else if (cnt2==m){
        cout<<start.fi+1<<' '<<start.sc<<endl;
    }
    else if (cnt3==m){
        cout<<start.fi<<' '<<start.sc-1<<endl;
    }
    else{
        cout<<start.fi<<' '<<start.sc+1<<endl;
    }
    return 0;

}