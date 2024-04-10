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
long check(long n,long s)
{
    long d=0;
    while(n)
    d+=n%10,n/=10;
    return d==s;
}
int main()
{
    io
    vl v;
    long n,c=0,i,d;
    cin>>n;
    d=n;
    while(d)
    d/=10,c++;
    for(i=0;i<=9*c+1;++i)
    if(check(n-i,i)) v.pb(n-i);
    sort(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for(i=0;i<v.size();++i)
    cout<<v[i]<<" ";
    return 0;
}