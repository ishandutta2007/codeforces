#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=1e6+10;
int n,k;
int num[mn];
int dp[mn];
int getmin(){
    dp[0]=1;
    for(int i=1;i<=min(100,k);i++)if(num[i]){
            for(int j=i;j<=k;j++)dp[j]+=dp[j-i];
            int lo=i*(num[i]+1);
            for(int j=k;j>=lo;j--){
                dp[j]-=dp[j-lo];
            }
            for(int j=0;j<=k;j++)dp[j]=(dp[j]>0);
        }
    bitset<mn>b;
    for(int i=0;i<=k;i++)b[i]=dp[i];
    for(int i=101;i<=k;i++)for(int j=0;j<num[i];j++)b|=b<<i;
    if(b[k])return k;
    else return k+1;
}
int getmax(){
    int two=0;
    for(int i=2;i<=n;i++){
        two+=(i/2)*num[i];
    }
    if(k<=two)return 2*k;
    return min(n,two+k);
}
int p[mn];
bool vis[mn];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",p+i);
    for(int i=1;i<=n;i++)if(!vis[i]){
            int len=1;
            vis[i]=1;
            for(int j=p[i];j!=i;j=p[j],len++)vis[j]=1;
            num[len]++;
        }
    int tot=0;
    for(int i=0;i<=n;i++)tot+=num[i]*i;
    printf("%d %d",getmin(),getmax());
}