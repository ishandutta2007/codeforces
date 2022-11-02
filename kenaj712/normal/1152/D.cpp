#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
const int mod=1e9+7;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<=a;x++)
        dp[x][0]=1;
    long long licz=0;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=a;y++)
        {
            dp[x][y]=dp[x-1][y]+dp[x][y-1];
            if(y>x)
                dp[x][y]=0;
            if((x+y)%2==1)
                licz+=dp[x][y];
            dp[x][y]%=mod;
        }
    licz+=(a+1)/2;
    cout<<licz%mod;
	return 0;
}