#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;

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

const ll DIM = 3E5+7;

const ll MOD = 1e9+7;

const ll INF = 1E9+70;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM],ans[DIM];
pp T[DIM*4];
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t] = {A[tl],A[tl]};
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t].fi = max(T[t*2+1].fi,T[t*2+2].fi);
    T[t].sc = min(T[t*2+1].sc,T[t*2+2].sc);
}
ll query(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (tr<l || r<tl)return -1;
    if (tl==tr){
        if (T[t].fi<val)return tl;
        return -1;
    }
    if (l<=tl && tr<=r)
        if (T[t].fi<val)return tr;

    ll tm = (tl+tr)/2;
    ll q1 = query(t*2+1,tl,tm,l,r,val);
    if ((q1==-1 && tm<l) || q1==tm){
        return max(query(t*2+2,tm+1,tr,l,r,val),q1);
    }
    else{
        return q1;
    }
}
ll query1(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (tr<l || r<tl)return -1;
    if (tl==tr){
        if (T[t].sc>val)return tl;
        return -1;
    }
    if (l<=tl && tr<=r)
        if (T[t].sc>val)return tr;

    ll tm = (tl+tr)/2;
    ll q1 = query1(t*2+1,tl,tm,l,r,val);
    if ((q1==-1 && tm<l) || q1==tm){
        return max(query1(t*2+2,tm+1,tr,l,r,val),q1);
    }
    else{
        return q1;
    }
}
ll T1[DIM*4][2],an[DIM][2];
void update(ll t,ll tl,ll tr,ll pos,ll val,ll ind){
    if (pos<tl || pos>tr)return;
    if (tl==tr){
        T1[t][ind] = val;
        return;
    }
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,pos,val,ind);
    update(t*2+2,tm+1,tr,pos,val,ind);
    T1[t][ind] = min(T1[t*2+1][ind],T1[t*2+2][ind]);
}
ll get(ll t,ll tl,ll tr,ll l,ll r,ll ind){
    if (l>tr || tl>r)return INF;
    if (l<=tl && tr<=r)return T1[t][ind];
    ll tm = (tl+tr)/2;
    return min(get(t*2+1,tl,tm,l,r,ind),get(t*2+2,tm+1,tr,l,r,ind));
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n)cin>>A[i];
    reverse(A+1,A+1+n);
    buildtree(0,1,n);
    forn(i,n){
        an[n-i+1][0] = n-query(0,1,n,i+1,n,A[i])+1;
        if (an[n-i+1][0]==n+2)an[n-i+1][0] = n-i+1;
        an[n-i+1][1] = n-query1(0,1,n,i+1,n,A[i])+1;
        if (an[n-i+1][1]==n+2)an[n-i+1][1] = n-i+1;
    }

    reverse(A+1,A+1+n);
    buildtree(0,1,n);

    priority_queue<pp,vector<pp>,greater<pp> > Q,Q1;
    for(ll i = 0;i<DIM*4;++i)T1[i][0] = T1[i][1] = INF;
    forn(i,n){
        ans[i] = INF;

        if (A[i-1]<A[i]){
            ans[i] = get(0,1,n,max(1,an[i][0]-1),i-1,0)+1;
        }
        else{
            ans[i] = get(0,1,n,max(1,an[i][1]-1),i-1,1)+1;
        }
        ans[i] = min(ans[i],ans[i-1]+1);
        if (i==1)ans[i] = 0;
        if (i==n)break;

        ll nxt = query(0,1,n,i+1,n,A[i]);

        if (nxt!=-1){
            ++nxt;
            update(0,1,n,i,ans[i],0);
            Q.push({nxt,i});
        }
        nxt = query1(0,1,n,i+1,n,A[i]);

        if (nxt!=-1){
            ++nxt;
            update(0,1,n,i,ans[i],1);
            Q1.push({nxt,i});
        }
        while(!Q.empty()){
            pp t = Q.top();
            if (t.fi>i)break;
            Q.pop();
            update(0,1,n,t.sc,INF,0);
        }
        while(!Q1.empty()){
            pp t = Q1.top();
            if (t.fi>i)break;
            Q1.pop();
            update(0,1,n,t.sc,INF,1);
        }
    }
    cout<<ans[n]<<endl;
    return 0;
}