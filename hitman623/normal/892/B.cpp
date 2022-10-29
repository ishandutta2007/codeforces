#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
long n,l[1000006],i,cur,v[1000006]={0},ans=0;
int main()
{
    io
    cin>>n;
    for(i=0;i<n;++i)
    cin>>l[i];
    cur=n-1-l[n-1];
    for(i=n-2;i>=0;--i)
    {
        if(cur<=i)
        v[i]=1;
        cur=min(cur,i-l[i]);
    }
    for(i=0;i<n-1;++i)
    ans+=!v[i];
    cout<<ans+1;
    return 0;
}