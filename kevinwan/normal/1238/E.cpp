#include<bits/stdc++.h>
using namespace std;
int num[20][20];
int dp[1<<20],h[1<<20];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    string s;
    cin>>s;
    for(int i=0;i<n-1;i++)num[s[i]-'a'][s[i+1]-'a']++,num[s[i+1]-'a'][s[i]-'a']++;
    for(int i=0;i<1<<m-1;i++){
        for(int j=0;j<m;j++)if((i>>j)&1)for(int k=0;k<m;k++)if((i>>k)&1^1)h[i]+=num[j][k];
    }
    for(int i=1<<m-1;i<1<<m;i++)h[i]=h[(1<<m)-1-i];
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<1<<m;i++){
        for(int j=0;j<m;j++)if((i>>j)&1){
            dp[i]=min(dp[i],dp[i^(1<<j)]);
        }
        dp[i]+=h[i];
    }
    printf("%d",dp[(1<<m)-1]);
}