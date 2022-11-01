#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

bool mark[70];
vector<int>v,vec;
int b[100],n,a,dp[110][100000],par[110][100000],ind;

int main()
{
    memset(dp,127,sizeof dp);
    for(int i=2;i<59;i++)
        if(!mark[i])
        {
            v.push_back(i);
            for(int j=i*i;j<59;j+=i)
                mark[j]=true;
        }
    int sz=v.size();
    for(int i=2;i<=60;i++)
        for(int j=0;j<sz;j++)
            if(i%v[j]==0)
                b[i]+=(1<<j);
    cin>>n;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        for(int j=0;j<(1<<sz);j++)
        {
            for(int x=1;x<59;x++)
            {
               // cout<<x<<" "<<b[x]<<" "<<(j&b[x])<<endl;
                if((j&b[x])==b[x])
                {
               //     cout<<x<<" "<<dp[i-1][j-b[x]]+abs(x-a)<<endl;
                    if(dp[i-1][j-b[x]]+abs(x-a)<dp[i][j])
                    {
                        par[i][j]=x;
                        dp[i][j]=dp[i-1][j-b[x]]+abs(x-a);
                    }
                }
            }
          //  cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<par[i][j]<<endl;
        }
    }
    int ans=100000000;
    for(int i=0;i<(1<<sz);i++)
    {
        if(dp[n][i]<ans)
        {
            ind=i;
            ans=min(ans,dp[n][i]);
        }
    }
    for(int i=n;i>0;i--)
    {
        int x=par[i][ind];
        vec.push_back(x);
        ind-=b[x];
    }
    for(int i=vec.size()-1;i>-1;i--)
        cout<<vec[i]<<" ";
    cout<<endl;
}