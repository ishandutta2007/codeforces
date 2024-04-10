#include <iostream>
#include<algorithm>

using namespace std;

int n,x,t[10000100],MAX=1,dp[10000100],m,r,l;
bool mark[10000100];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        MAX=max(MAX,x);
        t[x]++;
    }
    for(int i=2;i<=MAX;i++)
    {
        dp[i]=dp[i-1];
        if(mark[i])
            continue;
       // cout<<i<<endl;
        for(int j=i;j<=MAX;j+=i)
        {
            dp[i]+=t[j];
            mark[j]=true;
        }
    }
  //  for(int i=0;i<=MAX;i++)
    //    cout<<dp[i]<<" ";
    cin>>m;
    for(int i=0;i<m;i++)
    {
       cin>>l>>r;
        cout<<dp[min(r,MAX)]-dp[min(l-1,MAX)]<<endl;
    }
}