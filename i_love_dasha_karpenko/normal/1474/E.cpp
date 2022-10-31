#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
const ll DIM = 1E5+7;
ll P[DIM],ans[DIM];
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i){
            P[i] = i;
        }
        vector<pair<ll,ll> > edges;
        ll l = 1,r = n;
        edges.push_back({l,r});
        ll res = (n-1)*(n-1);
        ++l;
        --r;
        while(r-l>=0){
            if (l!=r){
                res+=2ll*(r-1)*(r-1);
                edges.push_back({1,r});
                edges.push_back({l,n});
            }
            if (l==r){
                res+=(r-1)*(r-1);
                edges.push_back({1,l});
            }
            ++l;
            --r;
        }



        reverse(edges.begin(),edges.end());
        for(auto to:edges){
            swap(P[to.first],P[to.second]);
        }
        for(ll i = 1;i<=n;++i){
            ans[P[i]] = i;
        }
        cout<<res<<endl;
        for(ll i = 1;i<=n;++i)cout<<ans[i]<<' ';
        cout<<endl;
        cout<<edges.size()<<endl;
        for(auto to:edges){
            if (ans[to.second]!=to.first)swap(to.first,to.second);
            swap(ans[to.first],ans[to.second]);
            cout<<to.first<<' '<<to.second<<endl;
        }
    }

    return 0;
}