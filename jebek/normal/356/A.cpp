#include <iostream>
#include<algorithm>

using namespace std;

const int MAXN=300100;
long long n,m,l,r,w,dp[MAXN],ans[MAXN];
bool mark[MAXN];

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>l>>r>>w;
        for(int j=l;j<w;j++)
        {
            if(mark[j])
            {
                int k=j;
                j=dp[j];
                dp[k]=max(dp[k],w-1);
            }
            else
            {
                mark[j]=true;
                dp[j]=w-1;
                ans[j]=w;
            }
        }
        for(int j=w+1;j<=r;j++)
        {
            if(mark[j])
            {
                int k=j;
                j=dp[j];
                dp[k]=max(dp[k],r-1);
            }
            else
            {
                mark[j]=true;
                dp[j]=r;
                ans[j]=w;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}