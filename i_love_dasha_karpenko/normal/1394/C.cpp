#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 3E5+7;
const ll INF = 1E17;
const ll MAXN = 1E6;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
pp A[DIM];
ll n;
pp F(ll r,ll out){
    pair<pp,pp> a = {{INF,-INF},{INF,-INF}};

    ll v1 = INF,v2 = -INF;
    forn(i,n){
        a.fi.fi =min(a.fi.fi,A[i].fi);
        a.fi.sc = max(a.fi.sc,A[i].fi);
        a.sc.fi =min(a.sc.fi,A[i].sc);
        a.sc.sc = max(a.sc.sc,A[i].sc);
        v1 = min(v1,A[i].sc-A[i].fi);
        v2 = max(v2,A[i].sc-A[i].fi);
    }
    if (a.fi.sc-a.fi.fi>r*2 || a.sc.sc-a.sc.fi>r*2 || v2-v1>r*2)return {0,0};
    pp r1,r2;
    r1 = {a.fi.fi+r,a.fi.sc-r};
    r2 = {a.sc.fi+r,a.sc.sc-r};

    if (r1.fi>r1.sc)swap(r1.fi,r1.sc);
    if (r2.fi>r2.sc)swap(r2.fi,r2.sc);

    for(ll x = max(0ll,r1.fi);x<=r1.sc;++x){
        ll a1 = v2+x-r;
        ll a2 = v1+x+r;
        if (r2.fi<=a1 && a1<=r2.sc && (a1+x) && a1>=0){
            if (out)return {x,a1};
            return {1,1};
        }
        if (r2.fi<=a2 && a2<=r2.sc && (a2+x) && a2>=0){
            if (out)return {x,a2};
            return {1,1};
        }
    }
    return {0,0};
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    forn(i,n){
        string s;
        cin>>s;
        ll b = 0;
        for(ll to:s)b+=(to=='B');
        A[i] = {b,s.length()-b};
    }
    ll l = 0,r = MAXN;
    while(l!=r){
        ll tm = (l+r)/2;
        if (F(tm,0).fi)r = tm;
        else l = tm+1;
    }
    cout<<l<<endl;
    pp ans = F(l,1);
    forn(i,ans.fi)cout<<'B';
    forn(i,ans.sc)cout<<'N';
    cout<<endl;
    return 0;
}