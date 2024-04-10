//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define endl '\n'
set<pair<ll,ll> > S;
const ll INF = 1E18;
const ll DIM = 2E5+7;
ll ans[DIM];

ll T[DIM][2];
void add(ll pos,ll delta,ll ind){
    for(ll i = pos;i<DIM;i+=i&-i)
        T[i][ind]+=delta;
}
ll get(ll pos,ll ind){
    ll ret = 0;
    for(ll i = pos;i>0;i-=i&-i)
        ret+=T[i][ind];
    return ret;
}
ll ask(ll pos){
    if (ans[pos]!=-1)
        return ans[pos];
    cout<<"? "<<1<<' '<<pos<<endl;
    cin>>ans[pos];
    ans[pos] = pos-ans[pos];
    ans[pos]+=get(pos,1);
    S.insert({ans[pos],pos});
    return ans[pos];
}
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    ll n,t;
    cin>>n>>t;
    memset(ans,-1,sizeof(ans));
    while(t--){
        ll k;
        cin>>k;
        ll tl = 1,tr = n;
        while(tl!=tr){
            ll tm = (tl+tr)/2;
            if (tm-get(tm,0)<k)
                tl = tm+1;
            else tr = tm;
        }
        k = tl;

        ll l,r;
        auto it = S.upper_bound({k-1,INF});
        if (it==S.begin() || S.empty()){
            l = 1;
        }
        else{
            it = prev(it);
            l = it->second+1; //0011 2 1 1
        }
        it = S.lower_bound({k,0});
        if (it!=S.end())
            r = it->second;
        else r = n;
        while(l!=r){
            ll tm = (l+r)/2;
            if (ask(tm)<k)
                l = tm+1;
            else
                r = tm;
        }
        cout<<"! "<<l<<endl;
        add(k,1,0);
        add(l,1,1);
    }
    return 0;
}