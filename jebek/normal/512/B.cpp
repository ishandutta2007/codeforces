#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

long long n,a[400],k,b[400],dp[10000],f,ans=100000000000000;
vector<int>v;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0)
            k=a[i];
        else
            k=__gcd(k,a[i]);
    }
    for(int j=0;j<n;j++)
        cin>>b[j];
    if(k>1)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int q=0;q<n;q++)
    {
        swap(a[q],a[0]);
        swap(b[q],b[0]);
        memset(dp,127,sizeof dp);
        f=a[0];
        v.clear();
        for(long long i=2;i*i<=f;i++)
            if(f%i==0)
            {
                v.push_back(i);
                while(f%i==0)
                    f/=i;
            }
        if(f>1)
            v.push_back(f);
        int m=v.size();
        dp[(1<<m)-1]=b[0];
        for(int i=1;i<n;i++)
        {
            f=0;
            for(int j=0;j<v.size();j++)
                if(a[i]%v[j]==0){
                    f+=(1<<j);
                }
                 //7   cout<<q<<" "<<i<<" "<<a[i]<<" "<<f<<endl;
            for(int j=0;j<(1<<m);j++)
                dp[f&j]=min(dp[f&j],dp[j]+b[i]);
        }
        ans=min(ans,dp[0]);
    }
    cout<<ans<<endl;
}