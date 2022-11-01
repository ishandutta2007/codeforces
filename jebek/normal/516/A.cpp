#include <iostream>
#include<vector>
#include<string>
#include<set>
#include<map>

using namespace std;

int n,a[5],dp[5];

int main()
{
    cin>>n;
    a[0]=2,a[1]=3,a[2]=5,a[3]=7;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        int k=int(c-'0');
        for(int j=2;j<=k;j++)
        {
            int x=j;
            for(int u=0;u<4;u++)
                while(x%a[u]==0)
                    dp[u]++,x/=a[u];
        }
    }
    for(int i=3;i>-1;i--)
    {
        while(dp[i]>0)
        {
            cout<<a[i];
            for(int j=2;j<=a[i];j++)
            {
                int x=j;
                for(int u=0;u<4;u++)
                    while(x%a[u]==0)
                        dp[u]--,x/=a[u];
            }
        }
    }
    cout<<endl;
}