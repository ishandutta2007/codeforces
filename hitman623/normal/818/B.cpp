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

int main()
{
    io
    long n,m,i,a[102]={0},b[102],d,v[102]={0};
    cin>>n>>m;
    for(i=0;i<m;++i)
    cin>>b[i];
    set < long > s;
    for(i=0;i<m-1;++i)
    {
        d=(b[i+1]-b[i]+n)%n;
        if(d==0) d=n;
        if(a[b[i]]!=0 && a[b[i]]!=d) {cout<<-1;exit(0);}
        if(v[d]!=0 && v[d]!=b[i]) {cout<<-1;exit(0);}
        a[b[i]]=d;
        v[d]=b[i];
        s.insert(a[b[i]]);
    }
    long j=1;
    for(i=1;i<=n;++i)
    if(a[i]==0)
    {
        while(s.find(j)!=s.end())
        j++;
        a[i]=j;
        s.insert(j);
    }
    for(i=1;i<=n;++i)
    cout<<a[i]<<" ";
    return 0;
}