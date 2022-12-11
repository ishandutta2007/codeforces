#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int bo[6000][6000],l[6000][6000],n,dp[6000][6000];
char ch[6000];
const int mo=1e9+7;
int main(){
    scanf("%d",&n);
    scanf("%s",ch+1);
    for (int i=1;i<=n;i++) bo[i][n+1]=1;
    for (int i=n;i;i--)
        for (int j=i+1;j<=n;j++)
            if (ch[i]>ch[j]){
                bo[i][j]=1; l[i][j]=0;
            } else if (ch[i]<ch[j]){
                bo[i][j]=0; l[i][j]=0;
            } else {
                bo[i][j]=bo[i+1][j+1]; l[i][j]=l[i+1][j+1]+1;
            }
    dp[1][1]=1;
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++){
            dp[i][j]=(dp[i][j-1]+dp[i][j])%mo;
            int ne=j+j-i+1,len=j-i+1;
            if (j==n||ch[j+1]=='0') continue;
            if (len<=l[i][j+1]) ne++;
            else if (bo[i][j+1]) ne++;
        //  cout<<"go "<<i<<" "<<j<<" "<<len<<endl;
            if (ne<=n) dp[j+1][ne]=(dp[j+1][ne]+dp[i][j])%mo;
        }
    int ans=0;
    for (int i=1;i<=n;i++) ans=(ans+dp[i][n])%mo;
    cout<<ans<<endl;
    return 0;
}