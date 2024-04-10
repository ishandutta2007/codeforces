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
const ll DIM = 5000 +7;
const ll INF = 10E17;

ll n,vis[DIM];
struct event{
    ll fi,sc,th,type;
};
vector<event> V;
bool mc(event a,event b){
    if (a.fi==b.fi)return a.type<b.type;
    return a.fi<b.fi;
}
ll T[DIM*2];
void add(ll pos,ll val){
    pos+=DIM;
    for(ll i = pos;i<DIM*2;i+=(i&-i))T[i]+=val;
}
ll sum(ll pos){
    pos+=DIM;
    ll ret = 0;
    for(ll i = pos;i>0;i-=(i&-i))ret+=T[i];
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;

    forn(i,n){
        ll x,y,x1,y1;
        cin>>x>>y>>x1>>y1;
        if (x>x1)swap(x,x1);
        if (y>y1)swap(y,y1);
        if (x==x1){
            V.pb({x,y,y1,1});
        }
        else{
            V.pb({x,y,i,0});
            V.pb({x1,y,i,2});
        }
    }
    sort(V.begin(),V.end(),mc);
    ll res = 0;
    for(ll i = 0;i<V.size();i++){
        event ev = V[i];
        if (ev.type==0){
            add(ev.sc,1);
            vis[ev.th] = 1;
        }
        else if (ev.type==2){
            add(ev.sc,-1);
            vis[ev.th] = 0;
        }
        else{
            vector<ll> vec;
            for(ll j = i+1;j<V.size();j++){
                event ev1 = V[j];
                if (ev1.type==2 && vis[ev1.th]==1){
                    add(ev1.sc,-1);
                    vec.pb(j);
                }
                else if (ev1.type==1){
                    ll s = sum(min(ev1.th,ev.th))-sum(max(ev1.sc,ev.sc)-1);
                    if (s>0)
                    res+=s*(s-1)/2;
                }
            }
            for(ll to:vec){
                event ev1 = V[to];
                add(ev1.sc,1);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}