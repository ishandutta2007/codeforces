#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=20;
double dp[1<<mn],p[mn],ans[mn];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int num=0;
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(p[i]!=0)num++;
    }
    if(num<=k){
        for(int i=0;i<n;i++){
            if(p[i]==0)printf("0 ");
            else printf("1 ");
        }
        return 0;
    }
    dp[0]=1;
    for(int i=0;i+1<1<<n;i++){
        double d=1;
        for(int j=0;j<n;j++)if((i>>j)&1)d-=p[j];
        for(int j=0;j<n;j++)if((i>>j)&1^1){
            dp[i|(1<<j)]+=dp[i]*p[j]/d;
        }
    }
    for(int i=0;i<1<<mn;i++){
        if(__builtin_popcount(i)!=k)continue;
        for(int j=0;j<n;j++)if((i>>j)&1)ans[j]+=dp[i];
    }
    for(int i=0;i<n;i++)printf("%.20lf ",ans[i]);
}