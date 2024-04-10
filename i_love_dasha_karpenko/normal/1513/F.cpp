#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 8E5+7;
const ll MOD = 1E9+7;
const ll INF = 1E18;
pair<ll,ll> A[DIM];
bool mc(pair<ll,ll> &a,pair<ll,ll> &b){
    return a.second<b.second;
}
ll T[DIM*4][2],mod[DIM*4][2];
void push(ll t){
    for(ll ind = 0;ind<=1;++ind)
    for(ll i = t*2+1;i<=t*2+2;++i){
        T[i][ind] = min(T[i][ind],mod[t][ind]);
        mod[i][ind] = min(mod[i][ind],mod[t][ind]);
    }
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll val,ll ind){
    if (l>tr || tl>r)
        return;
    if (l<=tl && tr<=r){
        T[t][ind] = min(T[t][ind],val);
        mod[t][ind] = min(mod[t][ind],val);
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,val,ind);
    update(t*2+2,tm+1,tr,l,r,val,ind);
    T[t][ind] = min(T[t*2+1][ind],T[t*2+2][ind]);
}
ll get(ll t,ll tl,ll tr,ll l,ll r,ll ind){
    if (tl>r || l>tr)
        return INF;
    if (l<=tl && tr<=r)
        return T[t][ind];
    push(t);
    ll tm = (tl+tr)/2;
    return min(get(t*2+1,tl,tm,l,r,ind),get(t*2+2,tm+1,tr,l,r,ind));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll res = 0;
    vector<pair<ll,ll> > V1,V2;
    set<ll> S;
    map<ll,ll> M;
    for(ll i = 1;i<=n;++i){
        cin>>A[i].first;
        S.insert(A[i].first);
    }
    for(ll i = 1;i<=n;++i){
        cin>>A[i].second;
        S.insert(A[i].second);
        res += abs(A[i].first-A[i].second);
    }
    ll cr = 0;
    for(ll to:S){
        M[to] = ++cr;
    }
    for(ll i = 1;i<=n;++i){
        if (A[i].first<A[i].second){
            V1.push_back(A[i]);
        }
        else{
            V2.push_back(A[i]);
        }
    }
    sort(V1.begin(),V1.end(),mc);
    sort(V2.begin(),V2.end());
    ll ptr = 0;
    ll r = 0;

    for(auto to:V2){
        while(ptr<V1.size() && V1[ptr].second<=to.first){
            update(0,1,cr,1,M[V1[ptr].first],-2*V1[ptr].second+2*V1[ptr].first,0);
            update(0,1,cr,M[V1[ptr].first],cr,-2*V1[ptr].second,1);
            ++ptr;
        }
        r = min({r,get(0,1,cr,M[to.second],cr,0),get(0,1,cr,1,M[to.second],1)+2*to.second});
    }
    for(ll i = 0;i<V1.size();++i){
        swap(V1[i].first,V1[i].second);
    }
    for(ll i = 0;i<V2.size();++i){
        swap(V2[i].first,V2[i].second);
    }
    swap(V1,V2);
    sort(V1.begin(),V1.end(),mc);
    sort(V2.begin(),V2.end());
    ptr = 0;
    memset(T,0,sizeof(T));
    memset(mod,0,sizeof(mod));
    for(auto to:V2){
        while(ptr<V1.size() && V1[ptr].second<=to.first){
            update(0,1,cr,1,M[V1[ptr].first],-2*V1[ptr].second+2*V1[ptr].first,0);
            update(0,1,cr,M[V1[ptr].first],cr,-2*V1[ptr].second,1);
            ++ptr;
        }
        r = min({r,get(0,1,cr,M[to.second],cr,0),get(0,1,cr,1,M[to.second],1)+2*to.second});
    }
    cout<<res+r<<endl;
    return 0;
}