#include <iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

typedef long double ld;
ld n,m;
ld d=1,ans;

int main()
{
    cin>>n>>m;
    for(ld i=n*m-n+1;i<=n*m;i++)
        d*=(i-n*m+n)/i;
   // cout<<d<<endl;
    d/=n;
    for(ld k=1;k<=min(n,m);k++)
    {
        ld f=d*k*k;
        for(ld i=k+1;i<=m;i++)
            f*=i;
        for(ld i=2;i<=m-k;i++)
            f/=i;
       // cout<<f<<endl;
        for(ld i=n*m-m-n+k+1;i<=n*m-m;i++)
            f*=i;
        for(ld i=2;i<=n-k;i++)
            f/=i;
        ans+=f;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}