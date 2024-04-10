#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
//#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 2E5+7;
const ll INF = 2E15;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
struct node{
    ll len,cnt,fi,sc;
    upp h;
};
const ll base = 3;
const ll MOD = 1E9+123;
ll gi(char ch){
    return ch-'0'+1;
}
upp rev;
upp po[DIM];
node T[DIM*4];
ll A[DIM];
node merge(node a,node b){
    if (a.len==-1 || b.len==-1)
        return a.len==-1?b:a;
    if (a.len>0 && b.len>0 && a.sc==2 && b.fi==2){
        b.h.fi-=(po[b.len-1].fi*2);
        b.h.sc-=(po[b.len-1].sc*2)%MOD;
        if (b.h.sc<0)b.h.sc+=MOD;

        a.h.fi-=2;
        a.h.sc-=2;
        if (a.h.sc<0)a.h.sc+=MOD;
        a.h.fi = (a.h.fi*rev.fi);
        a.h.sc = (a.h.sc*rev.sc)%MOD;
        a.cnt++;
        a.len--;
        b.len--;
        a.sc = 1;
        b.fi = 1;
        if (a.len==1)a.fi = 1;
        if (b.len==1)b.sc = 1;
        if (a.len==0)a.fi = a.sc = 0;
        if (b.len==0)b.fi = b.sc = 0;

    }
    a.h.fi = (a.h.fi*po[b.len].fi);
    a.h.sc = (a.h.sc*po[b.len].sc)%MOD;
    a.h.fi = (a.h.fi+b.h.fi);
    a.h.sc = (a.h.sc+b.h.sc)%MOD;
    if (b.len!=0)a.sc = b.sc;
    if (a.len==0)a.fi = b.fi;
    a.cnt+=b.cnt;
    a.len+=b.len;

    return a;
}

void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t].len = 1;
        T[t].fi = T[t].sc = A[tl];
        T[t].h = {A[tl],A[tl]};
        T[t].cnt = 0;
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = merge(T[t*2+1],T[t*2+2]);
}
node query(ll t,ll tl,ll tr,ll l,ll r){
    if (tl>r || l>tr)return {-1,-1,-1,-1,{-1,-1}};
    if (l<=tl && tr<=r)return T[t];
    ll tm = (tl+tr)/2;
    return merge(query(t*2+1,tl,tm,l,r),query(t*2+2,tm+1,tr,l,r));
}
const bool operator==(const node &a,const node &b){
    return a.fi==b.fi && a.sc==b.sc && a.h.fi==b.h.fi && a.h.sc==b.h.sc && a.cnt==b.cnt && a.len==b.len;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    po[0] = {1,1};
    forn(i,n){
        po[i].fi = po[i-1].fi*base;
        po[i].sc = (po[i-1].sc*base)%MOD;
    }
    {
        ll power = MOD-2;
        ll x = 1;
        ll mult = 3;
        while(power>0){
            if (power&1)x = (x*mult)%MOD;
            power/=2;
            mult = (mult*mult)%MOD;
        }
        rev.sc = x;
    }
    {
        ull aa= 0;
        aa--;
        ull power = aa;
        ull mult = 3;
        ull x = 1;
        while(power>0){
            if (power&1)x = x*mult;
            mult*=mult;
            power/=2;
        }
        rev.fi = x;
    }
    forn(i,n){
        char ch;
        cin>>ch;
        A[i] = ch-'0'+1;
    }
    buildtree(0,1,n);

    ll q;
    cin>>q;
    while(q--){
        ll l1,l2,len;
        cin>>l1>>l2>>len;
        node n1 = query(0,1,n,l1,l1+len-1);
        node n2 = query(0,1,n,l2,l2+len-1);
        if (n1==n2){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
    return 0;
}
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,