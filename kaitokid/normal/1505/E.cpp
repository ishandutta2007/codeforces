#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
char c[10][10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>c[i][j];
    int i=1,j=1,ans=0;

    while(i<n||j<m)
    {
        if(c[i][j]=='*')ans++;
        if(j==m){i++;continue;}
        if(i==n){j++;continue;}
        if(c[i][j+1]=='*'){j++;continue;}
        if(c[i+1][j]=='*'){i++;continue;}
    j++;
    }
    if(c[n][m]=='*')ans++;
    cout<<ans;
        return 0;
}