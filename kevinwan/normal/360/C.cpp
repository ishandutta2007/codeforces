#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=2e3+10;
string s;
ll dp[mn][mn],su[mn];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    cin>>s;
    s=" "+s;
    dp[0][0]=1;
    su[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++)dp[i][j]=su[j]*(s[i]-'a');
        for(int j=0;j<=k;j++){
            for(int l=1;l<=i&&l*(n+1-i)<=j;l++)dp[i][j]+=dp[i-l][j-l*(n+1-i)]*(25-(s[i]-'a'));
            dp[i][j]%=mod;
            su[j]+=dp[i][j],su[j]%=mod;
        }
    }
    printf("%lld",su[k]);
}