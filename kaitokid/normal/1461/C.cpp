#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ans[509][509],lf[509][509],ri[509][509];
string s[509];
int main()
{
    ios::sync_with_stdio(0);
int t,n,m;
cin>>t;
while(t--)
{
    cin>>n>>m;
    int u=-1,x;
    for(int i=1;i<=n;i++ )
    {
        cin>>x;
        if(x!=i)u=i;
    }
double ans=0,r,p;
if(u==-1)ans=1;
while(m--)
{
    cin>>r>>p;
    if(r>=u)ans=ans+(1-ans)*p;
}
cout<<fixed<<setprecision(6)<<ans<<endl;
}
    return 0;
}