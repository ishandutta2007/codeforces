#include <bits/stdc++.h>
#define int long long
using namespace std;

long long gcd(long long a, long long b)
{
    while ((a>0) and (b>0))
    {
        if (a>b)
            a%=b;
        else
            b%=a;
    }
    return max(a,b);
}

int a[100100];
int n;
int dp[100100];

int f(int i)
{
    if (dp[i]!=0)
        return dp[i];
    int c=a[i];
    for (int j=i+c; j<=n; j+=c)
      if (a[j]>a[i])
            if (f(j)==-1)
            {
                dp[i]=1;
                return dp[i];
            }
    for (int j=i-c; j>=1; j-=c)
        if (a[j]>a[i])
            if (f(j)==-1)
            {
                dp[i]=1;
                return dp[i];
            }
    return dp[i]=-1;
}

main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        if (f(i)==1)
            cout<<"A";
        else
            cout<<"B";
    cout<<"\n";
    return 0;

}