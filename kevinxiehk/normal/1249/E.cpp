#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
main(){
    int n,c;
    cin>>n>>c;
    int dp[n+5][3],arr[n+5][3];
    for(int i=0;i<=1;i++){
        for(int j=1;j<n;j++){
            cin>>arr[j][i];
        }
    }
    dp[0][0]=0;
    dp[0][1]=c;
    for(int i=1;i<n;i++){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+arr[i][0];
        dp[i][1]=min((dp[i-1][0]+c),dp[i-1][1])+arr[i][1];
        //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<min(dp[i][0],dp[i][1]);
        if(i==n-1)cout<<endl;
        else cout<<" ";
    }
    return 0;
}