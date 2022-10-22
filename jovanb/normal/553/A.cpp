#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long br[1001];
long long binom[1001][1001];
int main()
{
    long long i,j,n,broj,dp;
    binom[0][0]=1;
    for(i=1;i<=1000;i++){
        binom[i][0]=1;
        for(j=1;j<=i;j++){
            binom[i][j]=(binom[i-1][j]+binom[i-1][j-1])%mod;
        }
    }
    cin>>n;
    for(i=0;i<n;i++)cin>>br[i];
    dp=1;
    broj=br[0];
    for(i=1;i<n;i++){
        dp*=binom[broj+br[i]-1][br[i]-1];
        broj+=br[i];
        dp%=mod;
    }
    cout<<dp;
    return 0;
}