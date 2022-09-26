#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define int long long
#define pb push_back
#define fi first
#define se second

using namespace std;

int n;
int a[300500];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int l=0;
    for (int i=1; i<=n; i++)
    {
    if (a[i]!=a[n])
        l=max(l, n-i);
    if (a[i]!=a[1])
        l=max(l, i-1);
    }
    cout<<l<<"\n";
    return 0;
}