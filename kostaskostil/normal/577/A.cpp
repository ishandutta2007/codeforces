#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

main()
{
    int n, x;
    cin>>n>>x;
    int i=1;
    int ans=0;
    while (i*i<x)
    {
        if (x%i==0)
            if (x/i<=n)
                ans+=2;
        i++;
    }
    if (i*i==x)
        if (i<=n)
            ans++;
    cout<<ans<<"\n";
    return 0;
}