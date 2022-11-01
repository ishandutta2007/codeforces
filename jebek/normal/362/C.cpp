#include <iostream>
#include<set>
//#include<algorithm>

using namespace std;

int n,a[6000],dp1[6000],dp2[6000][6000],sum,MAX,t;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=n-1;i>-1;i--)
    {
        if(a[n-1]>a[i])
            dp2[i][n-1]=1;
        for(int j=n-2;j>i;j--)
        {
            dp2[i][j]=dp2[i][j+1];
            if(a[j]>a[i])
                dp2[i][j]++;
           // cout<<i<<" "<<j<<" "<<dp2[i][j]<<endl;
        }
    }
    for(int i=1;i<n;i++)
    {
        dp1[0]=0;
        if(a[0]>a[i])
            dp1[0]=1;
        for(int j=1;j<i;j++)
        {
            dp1[j]=dp1[j-1];
            if(a[j]>a[i])
                dp1[j]++;
        }
        for(int j=i-1;j>-1;j--)
        {
            if(a[j]>a[i])
            {
                sum++;
                int k=dp1[i-1]-dp1[j]-dp2[j][j+1]+dp2[j][i];
                k=k*2+1;
               // cout<<i<<" "<<j<<" "<<k<<" "<<dp1[i][i-1]<<" "<<dp1[i][j]<<" "<<dp2[j][j+1]<<" "<<dp2[j][i]<<endl;
                if(k>MAX)
                {
                    MAX=k;
                    t=1;
                }
                else if(k==MAX)
                    t++;
            }
        }
    }
    cout<<sum-MAX<<" "<<t<<endl;
}