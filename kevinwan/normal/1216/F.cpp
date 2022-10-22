#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=2e5+10;
ll dp[mn];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    string s;
    cin>>s;
    s=" "+s;
    priority_queue<pll,vector<pll>,greater<pll>>pq,bac;
    bac.push({0,0});
    for(int i=1;i<=n;i++){
        while(pq.size()&&pq.top().second<i)pq.pop();
        dp[i]=pq.size()?pq.top().first:0x3f3f3f3f3f3f3f3f;
        dp[i]=min(dp[i],dp[i-1]+i);
        if(s[i]=='1'){
            while(bac.top().second<i-k-1)bac.pop();
            ll pr=bac.top().first+i;
            dp[i]=min(dp[i],pr);
            pq.push({pr,i+k});
        }
        bac.push({dp[i],i});
    }
    printf("%lld",dp[n]);
}