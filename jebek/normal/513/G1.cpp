#include <iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

int n,q,a[40];
long double dp[300][40][40],ans;

int main()
{
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(int j=0;j<i;j++)
            if(a[j]>a[i])
                dp[0][j][i]=1;
    }
    for(int k=1;k<=q;k++)
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                for(int x=0;x<n;x++)
                    for(int y=x;y<n;y++)
                    {
                        int c=i;
                        if(x<=c && c<=y)
                            c=y-c+x;
                        int d=j;
                        if(x<=d && d<=y)
                            d=y-d+x;
                        if(c<=d)
                            dp[k][i][j]+=dp[k-1][c][d];
                        else
                            dp[k][i][j]+=1.0-dp[k-1][d][c];
                    }
              //  cout<<k<<" "<<i<<" "<<j<<" "<<dp[k][i][j]<<endl;
                dp[k][i][j]/=((long double)n*((long double)n+1.0))/2.0;
                if(k==q)
                    ans+=dp[k][i][j];
            }
    cout<<fixed<<setprecision(9)<<ans<<endl;
}