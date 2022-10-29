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
using namespace std;

int main()
{
    long n,a,b,x[101],y[101],i,ans=0,j;
    cin>>n>>a>>b;
    for(i=0;i<n;++i)
    cin>>x[i]>>y[i];
    for(i=0;i<n;++i)
    for(j=i+1;j<n;++j)
    {
        if(max(x[i],x[j])<=a && y[i]+y[j]<=b)
        ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        if(max(x[i],y[j])<=a && y[i]+x[j]<=b)
        ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        if(max(y[i],x[j])<=a && x[i]+y[j]<=b)
        ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        if(max(y[i],y[j])<=a && x[i]+x[j]<=b)
        ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        
        if(max(x[i],x[j])<=b && y[i]+y[j]<=a)
        ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        if(max(x[i],y[j])<=b && y[i]+x[j]<=a)
        ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        if(max(y[i],x[j])<=b && x[i]+y[j]<=a)
        ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        if(max(y[i],y[j])<=b && x[i]+x[j]<=a)
        ans=max(ans,x[i]*y[i]+x[j]*y[j]);
    }
    cout<<ans;
    return 0;
}