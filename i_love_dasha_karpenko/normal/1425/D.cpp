#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 1000;
ll A[DIM+1][DIM+1],sum[DIM+1][DIM+1],val[DIM*2+1];
ll n,m,r;
struct node{
    ll first,second,val;
};
node snakes[DIM*2+1];

ll get(ll x,ll y,ll x1,ll y1){
    x = max(1ll,x);
    y = max(1ll,y);
    x1 = min(x1,DIM);
    y1 = min(y1,DIM);
    return sum[x1][y1]-sum[x1][y-1]-sum[x-1][y1]+sum[x-1][y-1];
}
ll clk(ll x,ll y){
    return get(x-r,y-r,x+r,y+r);
}
struct node1{
    ll x,y,x1,y1;
};
ll inn(node1 a,node1 b){
    node1 c = {max(a.x,b.x),max(a.y,b.y),min(a.x1,b.x1),min(a.y1,b.y1)};
    ll r = max(0ll,c.x1-c.x+1)*max(0ll,c.y1-c.y+1);
    if (r==0)return 0;
    return get(c.x,c.y,c.x1,c.y1);
}
ll intersect(ll x,ll y,ll x1,ll y1){
    return inn({max(1ll,x-r),max(1ll,y-r),min(DIM,x+r),min(DIM,y+r)},{max(1ll,x1-r),max(1ll,y1-r),min(DIM,x1+r),min(DIM,y1+r)});

}
const ll DIMFACT = 1E4;
const ll MOD = 1E9+7;
ll fact[DIMFACT],re[DIMFACT];

ll binpow(ll x,ll power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)x = (x*mult)%MOD;
        mult = (mult*mult)%MOD;
        power/=2;
    }
    return x;
}
ll C(ll n,ll k){
    if (n<k)return 0;
    return fact[n]*re[n-k]%MOD*re[k]%MOD;
}
bool mc(node a,node b){
    if (a.first==b.first)return a.second<b.second;
    return a.first<b.first;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1;
    re[0] = 1;
    for(ll i = 1;i<DIMFACT;++i){
        fact[i] = (fact[i-1]*i)%MOD;
        re[i] = binpow(fact[i],MOD-2);
    }


    cin>>n>>m>>r;

    for(ll i = 1;i<=n;++i){
        ll x,y,b;
        cin>>x>>y>>b;

        snakes[i] = {x,y,b};
    }
    sort(snakes+1,snakes+1+n,mc);
    for(ll i = 1;i<=n;++i){
        A[snakes[i].first][snakes[i].second] = i;
    }
    for(ll i = 1;i<=DIM;++i){
        for(ll j = 1;j<=DIM;++j){
            sum[i][j] = (A[i][j]!=0)+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];

        }
    }

    ll res1 = 0;
    for(ll i = 1;i<=DIM;++i){
        for(ll j = 1;j<=DIM;++j){
            if (A[i][j]!=0){
                ll cnt = get(snakes[A[i][j]].first-r,snakes[A[i][j]].second-r,snakes[A[i][j]].first+r,snakes[A[i][j]].second+r);
                ll comb = ((C(n,m)-C(n-cnt,m))%MOD+MOD)%MOD;
                res1 = ((snakes[A[i][j]].val*snakes[A[i][j]].val)%MOD*comb+res1)%MOD;
            }
        }
    }
    for(ll i = 1;i<=n;++i){
        ll sum = 0;
        for(ll j = 1;j<i;++j){
            ll c1 = clk(snakes[i].first,snakes[i].second);
            ll c2 = clk(snakes[j].first,snakes[j].second);
            ll in = intersect(snakes[i].first,snakes[i].second,snakes[j].first,snakes[j].second);
            c1-=in;
            c2-=in;
            ll comb = ((C(n-in,m)+C(n-c1-c2-in,m)-C(n-c1-in,m)-C(n-c2-in,m))%MOD+MOD)%MOD;
            sum = (comb*snakes[j].val+sum)%MOD;
            comb = ((C(n,m)-C(n-in,m))%MOD+MOD)%MOD;
            sum = (comb*snakes[j].val+sum)%MOD;
        }
        res1 = (sum*snakes[i].val*2+res1)%MOD;

    }

    cout<<res1<<endl;
    return 0;

}