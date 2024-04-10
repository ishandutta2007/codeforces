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
long n,m,i,ans=1e9+7,d;
vl v;
string a,b;
vl vv;
long sol(long j)
{
    vv.clear();
    long i,c=0;
    for(i=j;i<j+n;++i)
    if(a[i-j]!=b[i]) vv.pb(i+1-j),c++;
    return c;
}
int main()
{
    io
    cin>>n>>m>>a>>b;
    for(i=0;i<m-n+1;++i)
    if((d=sol(i))<ans)
    {
        ans=d;
        v=vv;
    }
    cout<<ans<<endl;
    for(i=0;i<v.size();++i)
    cout<<v[i]<<" ";
    return 0;
}