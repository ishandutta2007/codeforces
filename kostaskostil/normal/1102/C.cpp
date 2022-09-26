#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define int long long


int n, x, y;
int a[100500];

main()
{
    int t;
    cin>>n>>x>>y;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        cin>>t;
        if (t<=x)
            ans++;
    }
    if (x>y)
    {
        cout<<n<<"\n";
    }
    else
    {
        cout<<((ans+1)/2)<<"\n";
    }

}