#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=2e3+10;
map<ll,vector<int>> dp;
ll a[mn];
int top(vector<int>&v){
    return v[v.size()-1];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
    for(i=1;i<=n;i++){
        for(j=i-1;j>=0;j--){
            ll s=a[i]-a[j];
            if(!dp[s].size()||j>=top(dp[s]))dp[s].push_back(i);
        }
    }
    ll bes=0;
    int num=0;
    for(auto th:dp){
        if(th.second.size()>num)bes=th.first,num=th.second.size();
    }
    printf("%d\n",num);
    vector<int>s=dp[bes];
    while(s.size()){
        int r=top(s);
        s.pop_back();
        for(int l=r-1;l>=0;l--){
            if(a[r]-a[l]==bes){
                printf("%d %d\n",l+1,r);
                break;
            }
        }
    }
}