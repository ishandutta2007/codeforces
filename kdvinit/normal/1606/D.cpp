/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<int> a[n+1];
    for(int i=1; i<=n; i++)
    {
        a[i].push_back(0);
        for(int j=1; j<=m; j++) { int x; cin>>x; a[i].push_back(x); }
        a[i].push_back(i);
    }
    sort(a+1, a+n+1);

    int max1[n+1][m+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            max1[i][j]=a[i][j];
            if(i!=1) max1[i][j] = max(max1[i][j], max1[i-1][j]);
            if(j!=1) max1[i][j] = max(max1[i][j], max1[i][j-1]);
        }
    }

    int min2[n+1][m+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=m; j>=1; j--)
        {
            min2[i][j]=a[i][j];
            if(i!=1) min2[i][j] = min(min2[i][j], min2[i-1][j]);
            if(j!=m) min2[i][j] = min(min2[i][j], min2[i][j+1]);
        }
    }

    int min3[n+1][m+1];
    for(int i=n; i>=1; i--)
    {
        for(int j=1; j<=m; j++)
        {
            min3[i][j]=a[i][j];
            if(i!=n) min3[i][j] = min(min3[i][j], min3[i+1][j]);
            if(j!=1) min3[i][j] = min(min3[i][j], min3[i][j-1]);
        }
    }

    int max4[n+1][m+1];
    for(int i=n; i>=1; i--)
    {
        for(int j=m; j>=1; j--)
        {
            max4[i][j]=a[i][j];
            if(i!=n) max4[i][j] = max(max4[i][j], max4[i+1][j]);
            if(j!=m) max4[i][j] = max(max4[i][j], max4[i][j+1]);
        }
    }

    int l=-1, r=-1;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            int b1 = max1[i][j];
            int b2 = min2[i][j+1];
            int r1 = min3[i+1][j];
            int r2 = max4[i+1][j+1];
            if(r1>b1 && b2>r2) { l=i; r=j; break; }
        }
    }

    if(l==-1) { cout<<"NO"<<endl; return; }

    cout<<"YES"<<endl;
    char ans[n+1];
    for(int i=1; i<=n; i++) ans[i]='R';
    for(int i=1; i<=l; i++) ans[a[i][m+1]]='B';
    for(int i=1; i<=n; i++) cout<<ans[i];
    cout<<" ";
    cout<<r<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}