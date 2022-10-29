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
long n,x,y,i,f[2000006],s[2000006],ans=1e18,g,j,cur,v[2000006]={0};
int main()
{
    io
    cin>>n>>x>>y;
    for(i=0;i<n;++i)
    {
        cin>>g;
        f[g]++;
        s[g]+=g;
    }
    for(i=1;i<=2e6;++i)
    f[i]+=f[i-1],s[i]+=s[i-1];
    for(i=2;i<=2e6;++i)
    if(!v[i])
    {
        cur=0;
        g=max(0LL,i-(x+y-1)/y);
        for(j=i;j<=2e6;j+=i)
        cur+=(f[j-i+g]-f[j-i])*x+((f[j-1]-f[j-i+g])*j-(s[j-1]-s[j-i+g]))*y,v[j]=1;
        ans=min(ans,cur);
    }
    cout<<ans;
    return 0;
}