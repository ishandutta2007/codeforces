#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dst[509][509];
int x[250009],y[250008],z[250009];

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
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
         if(i!=j)   dst[i][j]=INT_MAX;

        for(int i=0;i<m;i++)
        {
            cin>>x[i]>>y[i]>>z[i];
            dst[x[i]][y[i]]=1;
            swap(x[i],y[i]);
            dst[x[i]][y[i]]=1;

        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
             dst[i][j]=min(dst[i][j]*1LL,dst[i][k]*1LL+dst[k][j]);
    ll ans=LLONG_MAX;
    for(int i=0;i<m;i++){
       ans=min(ans,(dst[1][x[i]]+dst[y[i]][n]+1)*1LL*z[i]);
       ans=min(ans,(dst[1][y[i]]+dst[x[i]][n]+1)*1LL*z[i]);
    for(int d=1;d<=n;d++)
    {
      //  if((dst[1][d]+dst[d][n]+min(dst[d][x[i]],dst[d][y[i]]))*1LL*z[i]==132)cout<<i<<" "<<d<<" "<<x[i]<<" "<<y[i]<<endl;
          ans=min(ans,(dst[1][d]+dst[d][n]+min(dst[d][x[i]],dst[d][y[i]]))*1LL*z[i]+2*z[i]);

    }
    }
    cout<<ans<<endl;

    }
    return 0;
}