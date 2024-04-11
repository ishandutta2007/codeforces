#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

const int nmax=500500;
int a[500500];
int b[500500];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ta, tb, k;
    cin>>n>>m>>ta>>tb>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
        cin>>b[i];
    b[m+1]=1e18;
    if (k>=min(m,n))
        cout<<"-1\n", exit(0);
    int ans=0;
    int j=1;

    for (int i=0; i<=k; i++)
    {
        while (b[j]<a[i+1]+ta)
            j++;
        if (j+k-i>m)
            cout<<"-1\n", exit(0);
        ans=max(ans, b[j+k-i]+tb);
    }
    cout<<ans<<"\n";
}