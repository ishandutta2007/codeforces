#include<bits/stdc++.h>
using namespace std;
long long dp[5];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,c;
	cin>>a;
	string b;
	cin>>b;
	for(int x=0;x<a;x++)
    {
        cin>>c;
        if(b[x]=='h')
            dp[0]+=c;
        else if(b[x]=='a')
            dp[1]=min(dp[0],dp[1]+c);
        else if(b[x]=='r')
            dp[2]=min(dp[1],dp[2]+c);
        else if(b[x]=='d')
            dp[3]=min(dp[2],dp[3]+c);
    }
    cout<<dp[3];
	return 0;
}