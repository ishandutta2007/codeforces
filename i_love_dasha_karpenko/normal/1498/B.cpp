//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 fdgfdgf
#define y1 fdhfdgfdg
#define endl '\n'
const ll DIM = 1E5+7;

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,W;
        cin>>n>>W;
        set<pair<ll,ll> > S;
        for(ll i = 1;i<=n;++i){
            ll x;
            cin>>x;
            S.insert({x,i});
        }
        ll res = 0;
        while(!S.empty()){
            ++res;
            ll len = W;
            while(!S.empty() && len>0){
                auto it = S.upper_bound({len+1,0});
                if (it==S.begin())break;
                it--;
                len-=it->first;
                S.erase(it);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}