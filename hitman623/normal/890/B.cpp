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
long n,i,x[200005],p[200005],m;
int main()
{
    io
    p[0]=1e9;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>x[i];
        p[x[i]]=i;
    }
    for(i=1;i<=2e5;++i)
    if(p[i] && p[m]>p[i])
    m=i;
    cout<<m;
    return 0;
}