#include <iostream>
#include<algorithm>

using namespace std;

long long n,a[100100],MAX,dp[100100];

int main()
{
    cin>>n;
    if(n==1)
    {
        cin>>a[0];
        cout<<1<<endl;
        return 0;
    }
    cin>>a[0]>>a[1];
    dp[1]=2;
    MAX=2;
    for(int i=2;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==a[i-1]+a[i-2])
            dp[i]=dp[i-1]+1;
        else
            dp[i]=2;
        MAX=max(MAX,dp[i]);
    }
    cout<<MAX<<endl;
}