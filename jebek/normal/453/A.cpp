#include <iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

long double m,ans,dp[200000];
int n;

long double pow(long double a,int b)
{
    long double c=1;
    while(b)
    {
        if(b%2)
            c*=a;
        a*=a;
        b/=2;
    }
    return c;
}

int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        dp[i]=pow((long double)i/m,n);
    for(int i=1;i<=m;i++)
        ans+=(dp[i]-dp[i-1])*(long double)i;
    cout<<fixed<<setprecision(4)<<ans<<endl;
}