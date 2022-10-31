#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define exp fgfdgd
const ll DIM = 1E5+7;
const ll INF = 1E9;
ll A[DIM];
pair<ll,ll> dp[DIM];
int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
        }
        reverse(A+1,A+1+n);
        dp[n+1] = {-INF,0};
        for(ll i = n;i>=1;--i){
            dp[i] = max(dp[i+1],{A[i],i});
        }
        ll ptr = 1;
        vector<pair<ll,ll> > ans;
        while(ptr<=n){
            ans.push_back({ptr,dp[ptr].second});
            ptr = dp[ptr].second+1;
        }
        //reverse(ans.begin(),ans.end());
        for(auto to:ans){
            for(ll i = to.second;i>=to.first;--i){
                cout<<A[i]<<' ';
            }
        }
        cout<<endl;
    }

    return 0;
}