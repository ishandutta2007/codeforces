#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll MAXN = 1E10;
const ll INF = 1E18;
pair<ll,ll> A[DIM];

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        map<ll,ll> M;
        for(ll i = 1;i<=n;++i){
            ll x;
            cin>>x;
            ++M[x];
        }
        vector<ll> V;
        ll sum = 0;
        for(auto to:M){
            V.push_back(to.second);
            sum+=to.second;
        }
        sort(V.begin(),V.end());
        ll ptr = 0;
        ll res = INF;

        for(ll num = 1;num<=n;++num){
            while(ptr<V.size() && V[ptr]<num){
                ++ptr;
            }
            res = min(res,sum-(V.size()-ptr)*num);
        }
        cout<<res<<endl;
    }
    return 0;
}