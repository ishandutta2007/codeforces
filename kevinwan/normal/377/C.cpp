#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=1e6+10;
const ll mod=998244353;
int a[100],t[100];
string s[100];
int dp[21][1<<20];
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n,greater<int>());
    scanf("%d",&m);
    for(int i=0;i<m;i++)cin>>s[i]>>t[i];
    for(int i=m-1;i>=0;i--){
        if(s[i]=="p"){
            for(int j=1;j<1<<m;j++){
                int l=__builtin_ctz(j);
                if(t[i]==1)dp[i][j]=a[l]+dp[i+1][j-(1<<l)];
                else dp[i][j]=-a[l]+dp[i+1][j-(1<<l)];
            }
        }
        else{
            if(t[i]==1){
                for(int j=0;j<1<<m;j++){
                    dp[i][j]=dp[i+1][j];
                    for(int k=0;k<m;k++)if((j>>k)&1){
                        dp[i][j]=max(dp[i][j],dp[i+1][j-(1<<k)]);
                    }
                }
            }
            else{
                for(int j=0;j<1<<m;j++){
                    dp[i][j]=dp[i+1][j];
                    for(int k=0;k<m;k++)if((j>>k)&1){
                        dp[i][j]=min(dp[i][j],dp[i+1][j-(1<<k)]);
                    }
                }
            }
        }
    }
    printf("%d",dp[0][(1<<m)-1]);
}