#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define sz(x) 1LL*x.size()
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
long n,a[200005],i,cur=1,f[200005],ans=0;
int main()
{
    io
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        f[a[i]]++;
    }
    for(i=1;i<=2e5;++i)
    ans+=max(0LL,f[i]-1);
    ans+=f[0];
    cout<<ans;
    return 0;
}