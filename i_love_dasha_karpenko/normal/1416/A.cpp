#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 3E5+7;

vector<ll> A[DIM];
ll dp[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i){
            ll x;
            cin>>x;
            A[x].push_back(i);
        }
        stack<pair<ll,ll> > S;
        for(ll i = n;i>=1;--i){
            if (A[i].empty())continue;
            ll mx = max(A[i][0],n-A[i].back()+1);
            ll last = A[i][0];
            for(ll to:A[i]){
                mx = max(to-last,mx);
                last = to;
            }
            while(!S.empty() && S.top().second>=mx)S.pop();
            S.push({i,mx});
        }
        ll cur = n+1;
        while(!S.empty()){
            pair<ll,ll> t = S.top();
            S.pop();
            while(cur!=t.second){
                --cur;
                dp[cur] = t.first;
            }
        }
        for(ll i = 1;i<=n;++i){
            if (dp[i]==0)cout<<"-1 ";
            else cout<<dp[i]<<' ';
            dp[i] = 0;
            A[i].clear();
        }
        cout<<endl;
    }
    return 0;
}