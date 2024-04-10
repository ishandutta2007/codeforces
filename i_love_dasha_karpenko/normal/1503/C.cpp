//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 fdgfdgf
#define y1 fdhfdgfdg
//#define endl '\n'
#define time fdgfdgdf
const ll DIM = 1E5+7;
const ll INF = 1E16;
struct node{
    ll first,second,pos;
};

const bool operator<(const node &a,const node &b){
    if (a.first==b.first){
        if (a.second==b.second)
            return a.pos<b.pos;
        return a.second<b.second;
    }
    return a.first<b.first;
}
ll T[DIM*4];
void update(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (tl>r || l>tr)return;
    if (l<=tl && tr<=r){
        T[t] = min(T[t],val);
        return;
    }
    T[t*2+1] = min(T[t*2+1],T[t]);
    T[t*2+2] = min(T[t*2+2],T[t]);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,val);
    update(t*2+2,tm+1,tr,l,r,val);
}
ll get(ll t,ll tl,ll tr,ll pos){
    if (tl>pos || tr<pos)return INF;
    if (tl==tr)
        return T[t];
    T[t*2+1] = min(T[t*2+1],T[t]);
    T[t*2+2] = min(T[t*2+2],T[t]);
    ll tm = (tl+tr)/2;
    return min(get(t*2+1,tl,tm,pos),get(t*2+2,tm+1,tr,pos));
}
vector<ll> V[DIM];
ll solve(ll n,node A[]){
    for(ll i = 0;i<DIM*4;++i){
        T[i] = INF;
    }

    update(0,1,n,1,1,0);
    ll r = INF;
    for(ll i = 1;i<=n;++i){
        for(ll to:V[i])r = min(r,to);
        if (i!=1){
            //if (A[i-1].first+A[i-1].second<A[i].first)

            update(0,1,n,i,i,r+A[i].first);
        }
        ll val = get(0,1,n,i);
        ll pos = lower_bound(A+1,A+1+n,node{A[i].first+A[i].second+1,0,0})-A-1;
        pos = min(pos,n);
        if (i+1<=pos)
            update(0,1,n,i+1,pos,get(0,1,n,i));
        ll vv = -A[i].first-A[i].second+val; // A[i+1].first-A[i].first-A[i].second;
        pos = max(pos,i);
        V[pos+1].push_back(vv);
    }
    for(ll i = 0;i<=n+2;++i){
        V[i].clear();
    }
    return get(0,1,n,n);
}
node A[DIM],S[3][DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        cin>>A[i].first>>A[i].second;
        res+=A[i].second;
        A[i].pos = i;
    }
    sort(A+1,A+1+n);
    ll pos = 0;

    for(ll i = 1;i<=n;++i){

        if (A[i].pos==1){
            pos = i;
            break;
        }
    }
    for(ll i = 1;i<=pos;++i){
        S[0][i] = A[i];
    }
    for(ll i = pos;i<=n;++i){
        S[1][i-pos+1] = A[i];
    }
    ll ptr = 1;
    for(ll i = 1;i<=n;++i){
        if (A[i].pos==1 && i!=1 && i!=n)continue;
        S[2][ptr++] = A[i];
    }
    cout<<res+min(solve(pos,S[0])+solve(n-pos+1,S[1]),solve(ptr-1,S[2]))<<endl;
    return 0;
}