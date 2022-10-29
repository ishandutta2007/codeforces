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
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,k,c[100005],v[100005]={0},ans=0,s=0,i,ss=0,x;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        cin>>c[i];
        s+=c[i];
    }
    for(i=0;i<k;++i)
    {
        cin>>x;
        v[x]=1;
        ss+=c[x];
    }
    for(i=1;i<=n;++i)
    {
        if(v[i]) ans+=(s-c[i])*c[i];
        else
        {
            ans+=ss*c[i];
            if(i!=1)
            {
                if(v[i-1]==0) ans+=c[i]*c[i-1];
            }
            else if(v[n]==0) ans+=c[n]*c[i];
            if(i!=n)
            {
                if(v[i+1]==0) ans+=c[i]*c[i+1];
            }
            else if(v[1]==0) ans+=c[1]*c[i];
        }
    }
    cout<<ans/2<<endl;
    return 0;
}