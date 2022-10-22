#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct matrix
{
    int a[103][102];
    matrix()
    {

        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)a[i][j]=0;
    }
    matrix operator * (matrix& u)
    {
        matrix prod=matrix();
        for(int i=0;i<101;i++)
            for(int j=i;j<101;j++)
            for(int k=j;k<101;k++)
        prod.a[i][k]=max(prod.a[i][k],a[i][j]+u.a[j][k]);
        return prod;
    }
};
matrix pw(matrix x,int k)
{
    matrix res=x;

    k--;
    while(k>0)
    {
        if(k%2)res=res*x;
        x=x*x;
        k/=2;
    }
    return res;
}
int a[109],k,n,dp[109];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>n>>k;
    vector<int>h,hs;
    for(int i=0;i<n;i++)
        {cin>>a[i];h.push_back(a[i]);}

    sort(h.begin(),h.end());
    hs.push_back(h[0]);
    for(int i=1;i<n;i++)if(h[i]>h[i-1])hs.push_back(h[i]);
    for(int i=0;i<n;i++)a[i]=lower_bound(hs.begin(),hs.end(),a[i])-hs.begin();
    matrix mtr=matrix();
    for(int st=0;st<n;st++)
    {
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++)
        {
            if(a[i]<st)continue;
            int u=0;
            for(int j=st;j<=a[i];j++)u=max(u,dp[j]);
            u++;
            dp[a[i]]=u;
        }
        for(int i=st;i<n;i++)mtr.a[st][i]=dp[i];

    }
    matrix g=pw(mtr,k);
    int ans=0;
    for(int i=0;i<n;i++)ans=max(ans,g.a[0][i]);
    cout<<ans;

}