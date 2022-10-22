#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=5e3+10;
int c[mn],dp[mn][mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>c[i];
        if(c[i]==c[i-1])i--,n--;
    }
    for(i=1;i<n;i++){
        for(j=0;j+i<n;j++){
            int r=j+i;
            dp[j][r]=min(dp[j][r-1],dp[j+1][r])+1;
            if(c[j]==c[r])dp[j][r]=min(dp[j][r],dp[j+1][r-1]+1);
        }
    }
    printf("%d",dp[0][n-1]);
}