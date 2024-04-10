#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[300009],a[300009];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    dp[0]=1;
    for(int i=0;i<n;i++){dp[i]=1;
        for(int j=max(0,i-500);j<i;j++)
          if((a[j]^i)<(a[i]^j))dp[i]=max(dp[i],dp[j]+1);

    }
    int res=0;
    for(int i=0;i<n;i++)res=max(res,dp[i]);
    cout<<res<<endl;

}
return 0;
}