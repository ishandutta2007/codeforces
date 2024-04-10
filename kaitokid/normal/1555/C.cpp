#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[2][100009];
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll m;
        cin>>m;
        for(int i=0;i<2;i++)
            for(int j=1;j<=m;j++)
        {
            cin>>sum[i][j];
            sum[i][j]+=sum[i][j-1];
        }
        ll ans=LLONG_MAX;
        for(int i=1;i<=m;i++)
            ans=min(ans,max(sum[0][m]-sum[0][i],sum[1][i-1]));
        cout<<ans<<endl;
         }
    return 0;
}