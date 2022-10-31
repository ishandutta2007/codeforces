#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ld,ld> pp;
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
const ll DIM = 1000+7;
const ld INF = 1e19;

ld a,b,c;
ld k;
pair<pp,pp> in(pp aa,pp bb){
    ld l1 = k*aa.fi+b;
    pp d1 = {-INF,-INF};
    if (aa.sc<=l1 && bb.sc>=l1)d1 = {aa.fi,l1};
    pp d2 = {-INF,-INF};
    ld l2 = k*bb.fi+b;
    if (aa.sc<=l2 && bb.sc>=l2)d2 = {bb.fi,l2};
    pp d3 = {-INF,-INF};
    ld l3 = (aa.sc-b)/k;
    if (aa.fi<=l3 && bb.fi>=l3)d3 = {l3,aa.sc};
    ld l4 = (bb.sc-b)/k;
    pp d4 = {-INF,-INF};
    if (aa.fi<=l4 && bb.fi>=l4)d4 = {l4,bb.sc};
    vector<pp> V;
    if (d1!=pp{-INF,-INF})V.pb(d1);
    if (d2!=pp{-INF,-INF})V.pb(d2);
    if (d3!=pp{-INF,-INF})V.pb(d3);
    if (d4!=pp{-INF,-INF})V.pb(d4);
    if (V.size()<2)return {{0,0},{0,0}};
    return {V[0],V[1]};
}
ld nd(pp a,pp b){
    return abs(a.fi-b.fi)+abs(a.sc-b.sc);
}
ld dist(pp a,pp b){
    return sqrt((a.fi-b.fi)*(a.fi-b.fi)+(a.sc-b.sc)*(a.sc-b.sc));
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>a>>b>>c;

    pp A,B;
    cin>>A.fi>>A.sc>>B.fi>>B.sc;
    if (b==0 || a==0){
        cout<<fixed<<setprecision(10)<<nd(A,B)<<endl;
        return 0;
    }
    k = -a/b;
    b = -c/b;
    pair<pp,pp> rr = in({min(A.fi,B.fi),min(A.sc,B.sc)},{max(A.fi,B.fi),max(A.sc,B.sc)});
    ld res = nd(A,B);
    res = min(res,nd(A,rr.fi)+dist(rr.fi,rr.sc)+nd(rr.sc,B));
    swap(rr.fi,rr.sc);
    res = min(res,nd(A,rr.fi)+dist(rr.fi,rr.sc)+nd(rr.sc,B));
    cout<<fixed<<setprecision(10)<<res<<endl;
    return 0;
}