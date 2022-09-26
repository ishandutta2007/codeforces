#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int n;
int a[100500];

main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=0;
    for (int i=2; i<n; i++)
        if (a[i]==0)
            if (a[i+1]==1)
                if (a[i-1]==1)
                    a[i+1]=0, ans++;
    cout<<ans<<"\n";
    return 0;
}