#include <bits/stdc++.h>
#pragma GCC optimize("O3")
 
#define fi first
#define se second
#define pb push_back
 
#define int long long
using namespace std;
 
int a[200500];
int n;
 
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int mx=0;
    for (int i=1; i<=n; i++)
    {
        int r=a[i]+mx;
        mx=max(r,mx);
        cout<<r<<" ";
    }
    cout<<"\n";
    return 0;
}