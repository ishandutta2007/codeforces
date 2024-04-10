#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
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
#define log sdfdsfdsf

const ll DIM = 2E5+7;

const ll MOD = 1e9+7;

const ll INF = 1E16+7;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
pp T[DIM*4];
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t] = {0,0};
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t].sc = T[t*2+1].sc+T[t*2+2].sc;
}
void update(ll t,ll tl,ll tr,ll pos,pp val){
    if (tr<pos || pos<tl)return;
    if (tl==tr){
        T[t] = val;
        return;
    }
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,pos,val);
    update(t*2+2,tm+1,tr,pos,val);
    T[t].fi = T[t*2+1].fi+T[t*2+2].fi;
    T[t].sc = T[t*2+1].sc+T[t*2+2].sc;
}
ll query(ll t,ll tl,ll tr,ll need){
    if (T[t].sc<=need)return T[t].fi;
    ll tm = (tl+tr)/2;
    ll ret = query(t*2+2,tm+1,tr,need);
    need-=min(need,T[t*2+2].sc);
    if (need==0)return ret;
    ret += query(t*2+1,tl,tm,need);
    return ret;
}
pp A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    set<pp> SS;
    map<pp,ll> M;
    forn(i,n){
        cin>>A[i].fi>>A[i].sc;
        SS.insert({abs(A[i].sc),A[i].fi});
    }
    ll ptr = 0;
    for(pp to:SS)M[to] = ++ptr;

    buildtree(0,1,ptr);
    ll cnt = 0;
    ll len = 0;
    set<ll> S;
    ll sum = 0;
    forn(i,n){

        if (A[i].sc<0)update(0,1,ptr,M[{-A[i].sc,A[i].fi}],{0,0});
        else update(0,1,ptr,M[{A[i].sc,A[i].fi}],{A[i].sc,1});
        if (A[i].fi==1){
            if (A[i].sc<0){
                --cnt;
                S.erase(-A[i].sc);
            }
            else {
                ++cnt;
                S.insert(A[i].sc);
            }
        }
        sum+=A[i].sc;

        ll ps = 0;
        if (!S.empty()){
            ps = (*S.begin());
        }
        else{
            cout<<sum<<endl;
            continue;
        }
        update(0,1,ptr,M[{ps,1}],{0,0});

        ll qr = query(0,1,ptr,cnt);
        cout<<(sum-qr)+qr*2<<endl;
        update(0,1,ptr,M[{ps,1}],{ps,1});
    }

    return 0;
}