#include <iostream>
#include <stdio.h>
#define N 1111
using namespace std;

long long count(long long x)
{
        if (x<=0) return 0;
        long long deg=10;
        long long ans=1;
        for (int i=1; i<=17; i++)
        {
                if (x<deg) return ans;
                if (x<deg*2) return ans+(x-deg+1);
                ans+=deg;
                deg*=10;
        }
        if (x==1000000000000000000) ans++;
    return ans;
}
long long state[N][2];
double dp[N][N];
double pos[N];
double k;
int main()
{
        /*cout<<count(1000000000000000000)<<endl;
        return 0;*/
        int n; cin>>n;
        for (int i=0; i<n; i++)
        {
                cin>>state[i][0]>>state[i][1];
                //int z=count(state[i][1])-count(state[i][0]-1);
                pos[i+1]=((double)(count(state[i][1])-count(state[i][0]-1)))/(state[i][1]-state[i][0]+1);
        }
        cin>>k;
        dp[0][0]=1;
        for (int i=1; i<=n; i++)
                dp[i][0]=dp[i-1][0]*(1-pos[i]);
        for (int i=1; i<=n; i++)
                for (int j=1; j<=n; j++)
                {
                        if (j<i) continue;
                        dp[j][i]=dp[j-1][i]*(1-pos[j])+dp[j-1][i-1]*pos[j];
                }
        double z=0;
        double ans=0;
        for (int i=0; i<=n; i++)
        {
                if (100*i >= k*n) ans+=dp[n][i]; 
        }
        printf("%.11lf\n",ans);
}