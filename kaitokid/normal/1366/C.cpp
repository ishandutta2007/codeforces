#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int d[33][33];
int v[66][3];
int main()
{
    ios::sync_with_stdio(0);
    int t,n,m,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
    for(int i=0;i<=n+m;i++)v[i][0]=v[i][1]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>d[i][j];
            v[i+j][d[i][j]]++;
        }

        int ans=0;
        for(int i=0;i<(n+m-1)/2;i++)ans+=min(v[i][0]+v[n+m-2-i][0],v[i][1]+v[n+m-2-i][1]);
        cout<<ans<<endl;
    }
    return 0;
}