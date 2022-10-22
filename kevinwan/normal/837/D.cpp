#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e5+10;
const ll lowinf=1e14;
int dp1[2][201][6001],dp2[2][201][6001];
pii v[201]
;int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,nn;
    cin>>n>>nn;
    int i,j,k;
    for(i=1;i<=n;i++){
        ll x;
        cin>>x;
        while(x%5==0)x/=5,v[i].first++;
        while(x%2==0)x/=2,v[i].second++;
    }
    memset(dp1,0xc0,sizeof(dp1));
    memset(dp2,0xc0,sizeof(dp2));
    dp2[0][0][0]=0;
    int mo=25;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            for(k=v[i].first;k<=mo*j;k++){
                dp1[i&1][j][k]=dp2[i&1^1][j-1][k-v[i].first]+v[i].second;
            }
        }
        for(j=0;j<=i;j++){
            for(k=0;k<=mo*j;k++){
                dp2[i&1][j][k]=max(dp2[i&1^1][j][k],dp1[i&1][j][k]);
            }
        }
    }
    int ans=0;
        for(j=0;j<=mo*i;j++){
            ans=max(ans,min(j,dp2[n&1][nn][j]));
        }
    printf("%d",ans);
}