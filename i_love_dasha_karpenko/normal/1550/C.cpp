#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 2E5+7;
int A[DIM],dp1[DIM],dp2[DIM];
int solve(){
    int n;
    cin>>n;

    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    dp1[0] = dp2[0] = 1;
    stack<pair<int,int> > S1,S2;
    for(int i = 1;i<=n;++i){
        dp1[i] = dp1[i-1];
        dp2[i] = dp2[i-1];
        while(!S1.empty() && S1.top().first>A[i])
            S1.pop();
        if (!S1.empty())
            dp1[i] = S1.top().second+1;
        else dp1[i] = 1;
        while(!S2.empty() && S2.top().first<A[i])
            S2.pop();
        if (!S2.empty())
            dp2[i] = S2.top().second+1;
        else dp2[i] = 1;
        S1.push({A[i],i});
        S2.push({A[i],i});
    }
    priority_queue<pair<int,int> > Q1,Q2;
    int last = 1,res = 0;
    for(int i = 1;i<=n;++i){
        while(!Q1.empty() && Q1.top().first>=A[i]){
            last = max(last,dp2[Q1.top().second]);
            Q1.pop();
        }
        while(!Q2.empty() && Q2.top().first>=-A[i]){
            last = max(last,dp1[Q2.top().second]);
            Q2.pop();
        }
        res+=i-last+1;
        Q1.push({A[i],i});
        Q2.push({-A[i],i});
    }
    cout<<res<<endl;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        assert(solve());
    return 0;
}