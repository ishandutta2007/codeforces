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
const ll DIM = 500+7;
const ll INF = 10E17;
const ll MAXN = 10E15*2+17;
ll dist(pp x,pp y){
    return abs(x.fi-y.fi)+abs(x.sc-y.sc);
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x,y,ax,ay,bx,by;
    cin>>x>>y>>ax>>ay>>bx>>by;
    vector<pp> dots;
    while(x<MAXN && y<MAXN){
        dots.pb({x,y});
        x = x*ax+bx;
        y = y*ay+by;
    }
    ll p1,p2,t; cin>>p1>>p2>>t;
    ll res = 0;
    for(ll i = 0;i<dots.size();i++){
        ll cnt = 0,cost = 0;
        pp last = {p1,p2};
        for(ll j= i;j<dots.size();j++){
            if (cost+dist(last,dots[j])>t)break;
            cost+=dist(last,dots[j]);
            last = dots[j];
            cnt++;
        }
        res = max(res,cnt);
    }
    for(ll i = 0;i<dots.size();i++){
        ll cnt = 0,cost = 0;
        pp last = {p1,p2};
        for(ll j= i;j>=0;j--){
            if (cost+dist(last,dots[j])>t)break;
            cost+=dist(last,dots[j]);
            last = dots[j];
            cnt++;
        }
        res = max(res,cnt);
    }
    cout<<res<<endl;
    return 0;
}