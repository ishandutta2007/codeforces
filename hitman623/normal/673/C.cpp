#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,c[5005],i,f[5005]={0},ans[5005]={0},m,j;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>c[i];
    for(i=0;i<n;++i)
    {
        memset(f,0,sizeof(f));
        m=0;
        for(j=i;j<n;++j)
        {
            f[c[j]]++;
            if(f[c[j]]>f[m]) m=c[j];
            if(f[c[j]]==f[m]) m=min(m,c[j]);
            ans[m]++;
        }
    }
    for(i=1;i<=n;++i)
    cout<<ans[i]<<" ";
    return 0;
}