#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 2E5+7;
const ll MOD = 1E9+7;
const ll INF = 1E9;
const ll LOG = 21;
ll A[DIM],T[LOG][DIM],po[LOG],pre[DIM];
ll n,p;
ll get(ll l,ll r){
    ll lg = pre[r-l+1];
    return __gcd(T[lg][l],T[lg][r-po[lg]+1]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    po[0] = 1;
    for(ll i = 1;i<LOG;++i)
        po[i] = po[i-1]*2;
    for(ll i = 1;i<DIM;++i){
        pre[i] = pre[i-1];
        if (po[pre[i]+1]<=i)++pre[i];
    }
    ll t;
    cin>>t;
    while(t--){

        cin>>n>>p;
        vector<pair<ll,ll> > V;
        set<pair<ll,ll> > S;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
            T[0][i] = A[i];
            S.insert({i,i});
            V.push_back({A[i],i});
        }

        for(ll lg = 1;po[lg]<=n;++lg){
            for(ll i = 1;i+po[lg]-1<=n;++i){
                T[lg][i] = __gcd(T[lg-1][i],T[lg-1][i+po[lg-1]]);
            }
        }
        sort(V.begin(),V.end(),greater<pair<ll,ll> >());
        long long res = 0;
        while(!V.empty()){
            ll pos = V.back().second;
            V.pop_back();
            if (A[pos]>p)
                break;
            ll l = 1,r = pos;
            while(l!=r){
                ll tm = (l+r)/2;
                if (get(tm,pos)==A[pos])r = tm;
                else l = tm+1;
            }
            ll L = l;
            l = pos,r = n;
            while(l!=r){
                ll tm = (l+r+1)/2;
                if (get(pos,tm)==A[pos])l = tm;
                else r = tm-1;
            }
            ll R = l;
            auto beg = prev(S.lower_bound({L,INF}));
            ll cnt = 0;
            ll nl = INF,nr = -INF;
            while(beg!=S.end() && beg->first<=R){
                nl = min(nl,beg->first);
                nr = max(nr,beg->second);
                ++cnt;
                auto nxt = next(beg);
                S.erase(beg);
                beg = nxt;
            }
            res+=(long long)(cnt-1)*A[pos];
            S.insert({nl,nr});
        }
        res+=(long long)(ll(S.size())-1)*p;
        cout<<res<<endl;
    }
    return 0;
}