#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum[409][409],g[409][409],s[409][409];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
        {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            g[i][j]=g[i-1][j];
            s[i][j]=s[i][j-1];
            char c;
            cin>>c;
            if(c=='1')sum[i][j]++; else g[i][j]++,s[i][j]++;

        }
        int ans=1000000000;
        for(int i=1;i<=n;i++)
            for(int j=i+4;j<=n;j++)
        {
            int mx=-100000000;

            for(int q=4;q<=m;q++)
            {
                int d=q-3;
                int r=sum[j-1][d]-sum[i][d];
                int p=g[j-1][d]-g[i][d];
                r+=s[j][d]+s[i][d];
                r-=p;
                mx=max(mx,r);
                int h=sum[j-1][q-1]-sum[i][q-1];
                h+=s[j][q-1]+s[i][q-1]+g[j-1][q]-g[i][q];

                ans=min(ans,h-mx);
            }

        }
        cout<<ans<<endl;

    }
    return 0;
}