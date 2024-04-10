#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

ll gi(char ch){
    return ch-'0';
}
const ll DIM = 1E5+7;
ll pr[64];
ll po(ll x){
    if (x<0)return 0;
    return pr[x];
}
ll calc(set<ll> S,ll val){
    if (S.empty())
        return 1;
    ll prev = -4,len = 0;
    ll ret = 0;
    for(ll to:S){
        if (to==prev+1){
            ++len;
            prev = to;
        }
        else{
            ret+=po(len-1);
            len = 1;
            prev = to;
        }
    }
    ret+=po(len-1);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pr[0] = 1;
    for(ll i = 1;i<63;++i){
        pr[i] = pr[i-1]*2;
    }
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll ptr = 0;
        vector<ll> ans;
        while(n>61){
            ans.push_back(++ptr);
            --n;
        }
        set<ll> S;
        for(ll i = 1;i<=n;++i){
            S.insert(i);
        }
        ll F = 0;
        while(!S.empty()){
            ll cnt = 0;
            ll flag = 0;
            ll prev = 0;
            ll fl = 0;
            set<ll> S1 = S;
            for(ll to:S){
                S1.erase(to);
                ll ct = calc(S1,to);
                prev = to;
                if (cnt+ct>=k){
                    fl = 1;
                    break;
                }
                cnt+=ct;
            }
            if (fl==0){
                F = 1;
                break;
            }
            k-=cnt;
            ans.push_back(prev+ptr);
            S.erase(prev);
            vector<ll> V;
            for(ll to:S){
                if (to>prev)break;
                V.push_back(to);
            }
            reverse(V.begin(),V.end());
            for(ll to:V){
                ans.push_back(to+ptr);
                S.erase(to);
            }
        }

        if (F || k!=1){
            cout<<"-1\n";
            continue;
        }
        for(ll to:ans)
            cout<<to<<' ';
        cout<<endl;
    }
    return 0;
}