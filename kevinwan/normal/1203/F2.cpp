#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
vector<pii>pos,neg;
int dp[60010];
int main(){
    int n,r;
    scanf("%d%d",&n,&r);
    for(int i=0;i<n;i++){
        pii p;
        scanf("%d%d",&p.first,&p.second);
        if(p.second<0)neg.push_back(p);
        else pos.push_back(p);
    }
    sort(pos.begin(),pos.end());
    int ans=0;
    for(pii p:pos){
        if(r>=p.first)r+=p.second,ans++;
    }
    for(int i=0;i<neg.size();i++)neg[i].second*=-1,neg[i].first=max(0,neg[i].first-neg[i].second);
    sort(neg.begin(),neg.end());
    for(pii p:neg){
        for(int i=60009;i>=max(p.second,p.first+p.second);i--){
            dp[i]=max(dp[i],dp[i-p.second]+1);
        }
    }
    int ex=0;
    for(int i=0;i<=r;i++)ex=max(ex,dp[i]);
    printf("%d",ans+ex);
}