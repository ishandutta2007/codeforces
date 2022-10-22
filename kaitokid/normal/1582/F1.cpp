#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[5009][8209];
vector<int>v[5009];
bool ans[8209];
int main()
{
    int n;
    scanf("%d",&n);
    for(int j=0;j<=5000;j++)
        for(int i=0;i<=8200;i++)
        dp[j][i]=n+1;
    dp[0][0]=0;
    ans[0]=true;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        v[x].push_back(i);
    }
    for(int i=1;i<=5000;i++)
    {
        if(v[i].empty())
        {
        for(int j=0;j<=8200;j++)
            dp[i][j]=dp[i-1][j];
            continue;
            }


        for(int j=0;j<=8200;j++)
        {
            dp[i][j]=dp[i-1][j];
            int u=(j^i);
            if(u>8200)continue;
            if(dp[i-1][u]==n+1)continue;
            vector<int>::iterator it=upper_bound(v[i].begin(),v[i].end(),dp[i-1][u]);
            if(it==v[i].end())continue;
            dp[i][j]=min(dp[i][j],(*it));
            ans[j]=true;
        }
    }

    int res=0;
for(int i=0;i<=8200;i++)if(ans[i])res++;
cout<<res<<endl;
for(int i=0;i<=8200;i++)if(ans[i])cout<<i<<" ";
    return 0;
}