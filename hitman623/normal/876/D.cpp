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
long n,p[300005],i,cur,a[300005]={0},ans=1,j;
int main()
{
    io
    cin>>n;
    cur=n-1;
    cout<<1<<" ";
    for(i=0;i<n;++i)
    {
        cin>>p[i];
        a[p[i]-1]=1;
        ans++;
        while(a[cur]==1) cur--,ans--;
        cout<<ans<<" ";
    }
    return 0;
}