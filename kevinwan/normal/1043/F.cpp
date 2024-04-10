#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=3e5+10;
int num[mn],a[mn];
vector<int>pf[mn];
bitset<mn>p;
bool vis[mn];
int h[64];
int dp[64];
int hail(vector<int>&v,int x){
    int ans=1;
    for(int i=0;x;x>>=1,i++)if(x&1)ans*=v[i];
    return ans;
}
int main(){
    p.set();
    for(int i=2;i*i<mn;i++)if(p[i]){
            for(int j=i*i;j<mn;j+=i)p[j]=0;
        }
    for(int i=2;i<mn;i++)if(p[i])for(int j=i;j<mn;j+=i)pf[j].push_back(i);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        for(int j=0;j<1<<pf[a[i]].size();j++)num[hail(pf[a[i]],j)]++;
    }
    int ans=0x3f3f3f3f;
    for(int i=0;i<n;i++){
        int hhhhh=hail(pf[a[i]],(1<<pf[a[i]].size())-1);
        if(vis[hhhhh])continue;
        vis[hhhhh]=1;
        for(int j=0;j<1<<pf[a[i]].size();j++)h[j]=num[hail(pf[a[i]],j)];
        for(int j=0;j<pf[a[i]].size();j++)for(int k=0;k<1<<pf[a[i]].size();k++)if(!((k>>j)&1))h[k]-=h[k+(1<<j)];
        memset(dp,0x3f,sizeof(dp));
        int m=1<<pf[a[i]].size();
        dp[m-1]=0;
        for(int j=0;j<m;j++){
            if(!h[j])continue;
            for(int k=0;k<m;k++)dp[k&j]=min(dp[k&j],dp[k]+1);
        }
        ans=min(ans,dp[0]+1);
    }
    printf("%d",ans>1000000?-1:ans);
}