#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define int long long

#define fi first
#define se second
#define pb push_back

using namespace std;

int a[100500];
int b[100500];

main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            int x;
            cin>>x;
            a[x]=i;
        }
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        b[i]=a[x];
    }
    int mn=b[n];
    int ans=0;
    for (int i=n-1; i>=1; i--)
    {
        if (b[i]>mn)
            ans++;
        mn=min(mn, b[i]);
    }
    cout<<ans<<"\n";
    return 0;
}