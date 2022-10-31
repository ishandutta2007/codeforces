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
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 2E5+7;
const ll MOD = 1e9+7;
const ll INF = 1E17;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

struct node{
    ll fi,sc,c;
};
node A[DIM];
map<ll,ll> M;
ll ptr = 0;
ll T[DIM*8][2],add[DIM*8][2];
void push(ll t,ll ind){
    T[t*2+1][ind]+=add[t][ind];
    T[t*2+2][ind]+=add[t][ind];
    add[t*2+1][ind]+=add[t][ind];
    add[t*2+2][ind]+=add[t][ind];
    add[t][ind] = 0;
}
void st(ll t,ll tl,ll tr,ll pos,ll val,ll ind){
    if (tl>pos || tr<pos)return;
    if (tl==tr){
        T[t][ind] = val;
        return;
    }
    push(t,ind);
    ll tm = (tl+tr)/2;
    st(t*2+1,tl,tm,pos,val,ind);
    st(t*2+2,tm+1,tr,pos,val,ind);
    T[t][ind] = max(T[t*2+1][ind],T[t*2+2][ind]);
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll val,ll ind){
    if (tl>r || l>tr)return;
    if (l<=tl && tr<=r){
        add[t][ind]+=val;
        T[t][ind]+=val;
        return;
    }
    push(t,ind);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,val,ind);
    update(t*2+2,tm+1,tr,l,r,val,ind);
    T[t][ind] = max(T[t*2+1][ind],T[t*2+2][ind]);
}
ll get(ll t,ll tl,ll tr,ll l,ll r,ll ind){
    if (tl>r || l>tr)return 0;
    if (l<=tl && tr<=r)return T[t][ind];
    push(t,ind);
    ll tm = (tl+tr)/2;
    return max(get(t*2+1,tl,tm,l,r,ind),get(t*2+2,tm+1,tr,l,r,ind));
}
bool mc(node a,node b){
    return a.sc<b.sc;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;


    set<ll> S;
    forn(i,n){
        cin>>A[i].fi>>A[i].sc>>A[i].c;
        A[i].c--;
        S.insert(A[i].fi);
        S.insert(A[i].sc);

    }
    for(ll to:S){
        M[to] = ++ptr;
    }
    forn(i,n){
        A[i].fi = M[A[i].fi];
        A[i].sc = M[A[i].sc];
    }
    sort(A+1,A+1+n,mc);
    forn(i,n){

        update(0,0,ptr,0,A[i].fi-1,1,A[i].c^1);

        ll val = get(0,0,ptr,0,A[i].sc,A[i].c^1);
        st(0,0,ptr,A[i].sc,val,A[i].c);
    }
    cout<<max(T[0][0],T[0][1])<<endl;



    return 0;
}