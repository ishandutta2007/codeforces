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
#define po(x) (1ll<<x)
const ll DIM = 500+7;
const ll INF = 10E17;
pp A[DIM];
ll suma = 0,sumb = 0;
ll n,k;
ll T[4*DIM],add[DIM*4];
void push(ll t){
    if (add[t]==0)return;
    T[t*2+1] = 1;
    T[t*2+2] = 1;
    add[t*2+1] = 1;
    add[t*2+2] = 1;
    add[t] = 0;
}
void update(ll t,ll tl,ll tr,ll l,ll r){
    if (tl>r || l>tr)return;
    if (l<=tl && tr<=r){
        add[t] = 1;
        T[t] = 1;
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r);
    update(t*2+2,tm+1,tr,l,r);
}
ll query(ll t,ll tl,ll tr,ll pos){
    if (tl>pos || tr<pos)return 0;
    if (tl==tr){
        return T[t];
    }
    push(t);
    ll tm = (tl+tr)/2;
    return max(query(t*2+1,tl,tm,pos),query(t*2+2,tm+1,tr,pos));
}
ll get(ll x){
    return query(0,0,k-1,x);
}
ll solve(){
    ll r = 0;
    ll s1 = suma;
    ll s2 = sumb;
    forn(i,n){
        if (A[i].fi+A[i].sc<k)continue;
        ll l = max(0ll,k-A[i].sc);
        ll r = min(k-1,A[i].fi);
        if (l>r)continue;
        //swap(l,r);
        vector<pp> rng;
        forn(i,k){
            if(get(i)==1){
                ll r1 = i-l;
                ll l1 = i-r;
                l1+=k;
                r1+=k;
                l1%=k;
                r1%=k;
                if (l1>r1){
                    rng.pb({l1,k-1});
                    rng.pb({0,r1});
                }
                else rng.pb({l1,r1});
            }
        }
        for(pp to:rng)update(0,0,k-1,to.fi,to.sc);
    }
    for(ll i = 0;i<k;++i){
        ll g = get(i);
        if(g==0)continue;
        ll ss = suma%k+sumb%k;
        ss-=i;
        if (ss<0)ss+=k;
        ss%=k;
        ll rr = (suma+sumb-i-ss)/k+i/k+ss/k;

        r = max(r,rr);

    }
    return r;
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>k;

    forn(i,n){
        cin>>A[i].fi>>A[i].sc;
        suma+=A[i].fi;
        sumb+=A[i].sc;
    }

    update(0,0,k-1,suma%k,suma%k);
    ll res = solve();

    cout<<res<<endl;

    return 0;
}