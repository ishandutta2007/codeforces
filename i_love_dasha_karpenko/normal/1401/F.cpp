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

const ll DIM = po(19)+7;
const ll INF = 1E19;
const ll MAXN = 26;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
struct node{
    ll val,l,r;
};
ll S[DIM],R[DIM],bl,A[DIM];
node T[DIM*2];
void update(ll t,ll tl,ll tr,ll pos,ll val,ll level = bl){
    if (tl>pos || tr<pos)return;
    if (tl==tr){
        T[t].val = val;
        return;
    }
    ll tm = (tl+tr)/2;
    R[level-1]^=R[level];
    S[level-1]^=R[level];
    R[level] = 0;
    if (S[level])swap(T[t].l,T[t].r);
    update(T[t].l,tl,tm,pos,val,level-1);
    update(T[t].r,tm+1,tr,pos,val,level-1);
    T[t].val = T[T[t].l].val+T[T[t].r].val;
    if (S[level])swap(T[t].l,T[t].r);
}
ll ptr = 0;
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t].val = A[tl];
        return;
    }
    ll tm = (tl+tr)/2;
    T[t].l = ++ptr;
    buildtree(ptr,tl,tm);

    T[t].r = ++ptr;
    buildtree(ptr,tm+1,tr);
    T[t].val = T[T[t].l].val+T[T[t].r].val;
}
ll get(ll t,ll tl,ll tr,ll l,ll r,ll level = bl){
    if (tl>r || l>tr)return 0;
    if (l<=tl && tr<=r)return T[t].val;
    ll tm = (tl+tr)/2;
    R[level-1]^=R[level];
    S[level-1]^=R[level];
    R[level] = 0;
    if (S[level])swap(T[t].l,T[t].r);
    ll sum = get(T[t].l,tl,tm,l,r,level-1)+get(T[t].r,tm+1,tr,l,r,level-1);
    if (S[level])swap(T[t].l,T[t].r);
    return sum;
}
int main(){
    //cout<<DIM<<endl;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
     ll q;
    cin>>q;
    bl = n;
    n = (1ll<<n);
    forn(i,n)cin>>A[i];
    buildtree(0,1,n);

    forn(i,q){
        ll type,num;
        cin>>type>>num;
        if (type==1){
            ll val;
            cin>>val;
            update(0,1,n,num,val);
        }
        if (type==2){
            R[num]^=1;
            S[num]^=1;
        }
        if (type==3){
            S[num+1]^=1;
        }
        if (type==4){
            ll val;
            cin>>val;
            cout<<get(0,1,n,num,val)<<endl;
        }

    }

    return 0;
}