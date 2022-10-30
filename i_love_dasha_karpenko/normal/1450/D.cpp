#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 3E5+7;
ll A[DIM],ans[DIM],L[DIM],R[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i)cin>>A[i];
        stack<pair<ll,ll> > S;
        S.push({0,0});
        for(ll i = 1;i<=n;++i){
            while(!S.empty() && S.top().first>=A[i])
                S.pop();

            L[i] = S.top().second+1;
            S.push({A[i],i});
           // S.pop();
        }
        while(!S.empty())S.pop();
        S.push({0,n+1});
        for(ll i = n;i>=1;--i){
            while(!S.empty() && S.top().first>=A[i])S.pop();
            R[i] = S.top().second-1;
            S.push({A[i],i});
           // S.pop();
        }
        vector<pair<ll,ll> > V;
        for(ll i = 1;i<=n;++i){
            V.push_back({R[i]-L[i]+1,A[i]});
        }
        sort(V.begin(),V.end());
        set<ll> SS;
        for(ll i = n;i>=1;--i){
            while(!V.empty() && V.back().first>=i){
                SS.insert(V.back().second);
                V.pop_back();
            }
            if (SS.size()==n-i+1 && *SS.rbegin()==n-i+1)ans[i] = 1;
            else ans[i] = 0;
        }
        for(ll i = 1;i<=n;++i)cout<<ans[i];
        cout<<endl;


    }
    return 0;
}