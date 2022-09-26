#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b)
{
    while ((a!=0) and (b!=0))
    {
        if (a>b)
            a%=b;
        else
            b%=a;
    }
    return max(a, b);
}


main()
{
    int n, m;
    cin>>n>>m;
    int d;
     int x;
    int sum=0;
    int summax=0;
    for (int i=1; i<=m; i++)
    {
        cin>>x>>d;
        sum+=n*x;
        if (d>0)
            sum+=d*n*(n-1)/2;
        else
        {
            sum+=d*(n/2)*(n/2+1)/2;
            sum+=d*(n-n/2)*(n-n/2-1)/2;
        }
    }
    cout<<setprecision(10)<<(sum+0.0)/n<<"\n";
}