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
long n,a[1000006]={0},i,ans=0,visi[1000006]={0},sum=0;
int main()
{
    io
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i],visi[a[i]]=n;
    for(i=n-1;i>=0;--i)
    {
        sum+=visi[a[i]]-i;
        visi[a[i]]=i;
        ans+=sum;
    }
    cout<<fixed<<setprecision(10);
    double d=2*ans-n,t=n,tt=d/(t*t);
    cout<<tt;
    return 0;
}