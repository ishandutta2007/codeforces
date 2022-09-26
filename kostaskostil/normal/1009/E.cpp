#include <bits/stdc++.h>
#define int long long
#define pow not_a_pow
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

int pow(int a, int b)
{
    if (b==0)
        return 1;
    if (b==1)
        return a;
    int x=pow(a, b/2);
    int y=pow(a, b%2);
    x*=x;
    x%=998244353;
    x*=y;
    x%=998244353;
    return x;
}

int n, m;
int a[1000100];
int dp[1000100];

int cat(int q)
{
    if (q==0)
        return 1;
    return (((q+2)*pow(2, q-1))%998244353);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int dx=cat(n-i);
        dx%=998244353;
        dx*=a[i];
        dx%=998244353;
        ans+=dx;
        ans%=998244353;
    }
    cout<<ans;
}