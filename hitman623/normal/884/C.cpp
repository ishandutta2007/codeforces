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

int main()
{
    io
    vl v;
    long n,p[100005],i,j,visi[100005]={0},ans=0;
    cin>>n;
    for(i=1;i<=n;++i)
    cin>>p[i];
    for(i=1;i<=n;++i)
    if(!visi[i])
    {
        j=i;
        long c=0;
        while(!visi[j])
        {
            visi[j]=1;
            j=p[j];
            c++;
        }
        v.pb(c);
        ans+=c*c;
    }
    n=v.size();
    sort(v.begin(),v.end());
    if(v.size()==1) cout<<ans;
    else cout<<ans-v[n-1]*v[n-1]-v[n-2]*v[n-2]+(v[n-1]+v[n-2])*(v[n-1]+v[n-2]);
    return 0;
}