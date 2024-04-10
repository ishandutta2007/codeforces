#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long n,q,c,x[100005],y[100005],s[100005],i,a[11][101][101]={0},ans,j,k,t,x1,x2,yy1,y2;
int main()
{
    io
    cin>>n>>q>>c;
    for(i=0;i<n;++i)
    cin>>x[i]>>y[i]>>s[i];
    for(i=0;i<=c;++i)
    {
        for(j=0;j<n;++j)
        a[i][x[j]][y[j]]+=s[j];
        for(j=1;j<=100;++j)
        for(k=1;k<=100;++k)
        a[i][j][k]+=a[i][j][k-1];
        for(j=0;j<n;++j)
        s[j]=(s[j]+1)%(c+1);
    }   
    while(q--)
    {
        ans=0;
        cin>>t>>x1>>yy1>>x2>>y2;
        t%=(c+1);
        for(i=x1;i<=x2;++i)
        ans+=a[t][i][y2]-a[t][i][yy1-1];
        cout<<ans<<"\n";
    }
    return 0;
}