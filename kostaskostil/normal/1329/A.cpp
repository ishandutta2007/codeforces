#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

const int nmax=500500;
int a[nmax];
int mx[nmax];
int ans[nmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
        cin>>a[i];
    mx[m]=n+1-a[m];
    for (int i=m-1; i>=1; i--)
        mx[i]=min(mx[i+1]-1, n+1-a[i]);
    if (mx[1]<1)
        cout<<"-1\n", exit(0);
    ans[1]=1;
    for (int i=2; i<=m; i++)
    {
        ans[i]=min(ans[i-1]+a[i-1], mx[i]);
    }
    if (ans[m]+a[m]<=n)
        cout<<"-1\n", exit(0);
    for (int i=1; i<=m; i++)
        cout<<ans[i]<<" ";
    return 0;

}