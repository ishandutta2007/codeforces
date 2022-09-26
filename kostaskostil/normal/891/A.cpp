#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define fi first
#define se second

using namespace std;

int a[100500];
int b;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    b=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]==1)
            b++;
    }
    if (b!=0)
    {
        cout<<n-b;
        exit(0);
    }
    int l=n+1;
    for (int i=1; i<=n; i++)
    {
        int p=a[i];
        if (p==1)
            l=1;
        for (int j=i+1; j<=n; j++)
        {
            p=__gcd(p, a[j]);
            if (p==1)
                l=min(l, j-i+1);
        }
    }

    if (l>n)
        cout<<"-1\n";
    else
        cout<<(l-1)+(n-1)<<"\n";

    return 0;
}