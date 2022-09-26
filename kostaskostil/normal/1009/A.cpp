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

int a[1000100];
int c[1000100];

main()
{
    int n, m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>c[i];
    for (int i=1; i<=m; i++)
        cin>>a[i];
    int cur=1;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        if (a[cur]>=c[i])
            ans++, cur++;
        if (cur>m)
        {
            cout<<ans<<"\n";
            exit(0);
        }
    }
    cout<<ans<<"\n";
    return 0;
}