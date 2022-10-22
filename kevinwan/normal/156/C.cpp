#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
const ll mod=1e9+7;
ll dp[2601][101];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,j,k;
    cin>>n;
    dp[0][0]=1;
    for(i=1;i<=2600;i++){
        for(j=1;j<=100;j++){
            for(k=i-1;k>=i-26&&k>=0;k--){
                dp[i][j]=(dp[i][j]+dp[k][j-1])%mod;
            }
        }
    }
    while(n--){
        string s;
        cin>>s;
        int sum=0;
        for(char c:s)sum+=c-'a'+1;
        printf("%lld\n",(dp[sum][s.size()]+mod-1)%mod);
    }
}